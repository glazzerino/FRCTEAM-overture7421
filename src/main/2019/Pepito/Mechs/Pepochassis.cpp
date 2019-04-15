#include "2019/Pepito/Mechs/Pepochassis.h"

PepoChassis::PepoChassis() :
FluxSubsystem("Pepochassis") {
    leftSlave.Set(ControlMode::Follower, leftVictor.GetDeviceID());
    rightSlave.Set(ControlMode::Follower, rightVictor.GetDeviceID());
    
    leftVictor.ConfigOpenloopRamp(ramp);
    rightVictor.ConfigOpenloopRamp(ramp);
    rightVictor.SetNeutralMode(Brake);
    leftVictor.SetNeutralMode(Brake);
    auto ntInstance = nt::NetworkTableInstance::GetDefault();
    visionTable = ntInstance.GetTable("ChickenVision");
    rightVictor.SetInverted(true);
    rightSlave.SetInverted(true);
}

void PepoChassis::robotInit() {
    
    rightVictor.ConfigVoltageCompSaturation(12.0,12.0);
    leftVictor.ConfigVoltageCompSaturation(12.0,12.0);
    rightVictor.EnableVoltageCompensation(true);
    leftVictor.EnableVoltageCompensation(true);
    
    std::cout << "DIREVTRAIN ONLINE\n"; 

    startTime = std::chrono::high_resolution_clock::now();
    //frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
    }

void PepoChassis::robotUpdate() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    nowTime = std::chrono::duration<double>(currentTime - startTime).count();
    YAW = visionTable->GetNumber("YAW", 0.0);
    
    //HANDS ARE SWAPPED DONT ASK
    leftJoystick = xbox.GetY(frc::XboxController::kRightHand);
    rightJoystick = xbox.GetY(frc::XboxController::kLeftHand);
    
     headingError = datapool.getData("Pepochassis","targetHeading") - gyro.GetAngle();
     headingOutput = headingError * 0.021;
     double timeStep = nowTime - lastUpdate;
     yawDelta = (YAW -lastYaw) / timeStep ;
     lastUpdate = nowTime;
     lastYaw = YAW;
}
    
void PepoChassis::teleopInit() {
     SmartDashboard::PutNumber("VISIOND", 0.003);
    SmartDashboard::PutNumber("VISIONP", 0.008);
    SmartDashboard::PutBoolean("RAMP", rampState);
    expJoys = true;
    frc::SmartDashboard::PutBoolean("ExpJoys", expJoys);
    toggleState = TOGGLE_HEADING::DONE;
}

void PepoChassis::teleopUpdate() {
    

    if (xbox.GetTriggerAxis(XboxController::kRightHand)> 0.1) {
        useJoys = false;
        std::cout << xbox.GetTriggerAxis(XboxController::kRightHand) << std::endl;
        double correction = 0;
        if(visionTable->GetBoolean("engaged", false)){
            correction = YAW * frc::SmartDashboard::GetNumber("VISIONP",0.0) + 
            yawDelta * SmartDashboard::GetNumber("VISIOND",0.0);
        }
        leftVictor.Power(xbox.GetTriggerAxis(XboxController::kRightHand) + correction);
        rightVictor.Power(xbox.GetTriggerAxis(XboxController::kRightHand)- correction);
    } else {
        leftVictor.Power(leftJoystick);
        rightVictor.Power(rightJoystick);
        
        if (xbox.GetStartButtonPressed()) {
            expJoys = !expJoys;
            frc::SmartDashboard::PutBoolean("ExpJoys", expJoys);
            xbox.setExpJoystick(expJoys);
        }
        if (xbox.GetYButton()) {
            useJoys = false;
            rightVictor.Power(1.0);
            leftVictor.Power(1.0);
        } else {
            useJoys = true;
        }
    }
    if (xbox.GetBumperPressed(XboxController::kLeftHand)) {
        if (rampState) {
            rightVictor.ConfigOpenloopRamp(ramp);
            leftVictor.ConfigOpenloopRamp(ramp);
            rampState = false;
            
        } else if (!rampState) {
            rightVictor.ConfigOpenloopRamp(0.0);
            leftVictor.ConfigOpenloopRamp(0.0);
            rampState = true;
        }
        SmartDashboard::PutBoolean("RAMP", rampState);
    }
    
    frc::SmartDashboard::PutNumber("Left Joystick", leftJoystick);
    frc::SmartDashboard::PutNumber("Right Joystick", rightJoystick);
    
}

void PepoChassis::autonInit(){
    SmartDashboard::PutNumber("VISIOND", 0.003);
    SmartDashboard::PutNumber("VISIONP", 0.008);
}

void PepoChassis::autonUpdate() {
        teleopUpdate();
}

void PepoChassis::disabledInit() {
    ;
}

void PepoChassis::disabledUpdate() {
    ;
}

void PepoChassis::toggleHeading() {
    switch (toggleState) {
        case TOGGLE_HEADING::ENGAGED:
            datapool.addData("Pepochassis", "targetHeading",gyro.GetAngle() + 180.0);
            toggleState = TOGGLE_HEADING::DOING;
            break;
        case TOGGLE_HEADING::DOING:
            
            rightVictor.Power(0.3+headingOutput);
            leftVictor.Power(-0.3-headingOutput);
            if (datapool.getData("Pepochassis", "targetHeading") == gyro.GetAngle()) {
                toggleState = TOGGLE_HEADING::DONE;
            }
            break;
        case TOGGLE_HEADING::DONE:
            swapSides = !swapSides;
            toggleState = TOGGLE_HEADING::IDLE;
            break;
        case TOGGLE_HEADING::IDLE:
            //std::cout << gyro.GetAngle() << "\n";
            break;
    }
}


