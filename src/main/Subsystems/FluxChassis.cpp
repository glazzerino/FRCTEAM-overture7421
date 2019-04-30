#include "Subsystems/FluxChassis.h"

FluxChassis::FluxChassis() : FluxSubsystem("FluxChassis") {
    leftSlave.Set(ControlMode::Follower, leftMaster.GetDeviceID());
    rightSlave.Set(ControlMode::Follower, rightMaster.GetDeviceID());

    rightMaster.SetInverted(true);

    rightMaster.ConfigVoltageCompSaturation(12.0);
    rightSlave.ConfigVoltageCompSaturation(12.0);
    leftMaster.ConfigVoltageCompSaturation(12.0);
    leftSlave.ConfigVoltageCompSaturation(12.0);
    
    leftMaster.ConfigOpenloopRamp(ramp);
    rightMaster.ConfigOpenloopRamp(ramp);
    rightMaster.EnableVoltageCompensation(true);
    leftMaster.EnableVoltageCompensation(true);
    auto nt = nt::NetworkTableInstance::GetDefault();
    visionTable = nt.GetTable("ChickenVision");
}

void FluxChassis::robotInit() {
    frc::SmartDashboard::PutNumber("Max ang vel vision", 30.0);
    frc::SmartDashboard::PutNumber("heading kP", 0.01);
    frc::SmartDashboard::PutNumber("heading kI", 0.0);
    frc::SmartDashboard::PutNumber("heading kD", 0.004);
    headingController.setUpperLimit(180.0);
    headingController.setLowerLimit(-180.0);
    headingController.setContinous(true);
}

void FluxChassis::robotUpdate() {
    maxAngularVelocityVision = frc::SmartDashboard::GetNumber("Max ang vel vision", 30.0);
    targetYaw = visionTable->GetNumber("YAW", 0.0);
    double kP = frc::SmartDashboard::GetNumber("heading kP", 0.0);
    double kI = frc::SmartDashboard::GetNumber("heading kI", 0.0);
    double kD = frc::SmartDashboard::GetNumber("heading kD", 0.0);
    frc::SmartDashboard::PutNumber("Gyro", navx.GetYaw());
    frc::SmartDashboard::PutNumber("TargetHeading", headingTarget);
    headingController.setP(kP);
    headingController.setI(kI);
    headingController.setD(kD);
    visionEngaged = visionTable -> GetBoolean("engaged", false);
    frc::SmartDashboard::PutNumber("Current error", headingController.getCurrentError());
}   

void FluxChassis::teleopInit() {
    navx.ZeroYaw();
}

void FluxChassis::teleopUpdate() {

    double rightHand = xbox.GetX(XboxController::kRightHand);
    double leftHand = xbox.GetY(XboxController::kLeftHand);

    if(rightHand > 0.0 && rightHand < 0.09){
        rightHand = 0.0;
    }

    if(rightHand < 0.0 && rightHand > -0.09){
        rightHand = 0.0;
    }
    double timeStep = chrono::duration<double>(chrono::high_resolution_clock::now() - lastUpdate).count();
    
    double headingChange = rightHand * timeStep * maxAngularVelocity;
    
    if (xbox.GetAButton() && visionEngaged) {
         headingTarget += (targetYaw / 10)* maxAngularVelocityVision * timeStep;
    } else {
        headingTarget += headingChange;
    }
    if (headingTarget > 180.0) {
        headingTarget -= 360.0;
    }
    if (headingTarget < -180.0) {
        headingTarget += 360.0;
    }
    headingController.setFeedback(navx.GetYaw());
    headingController.setTarget(headingTarget);
    double headingOutput = headingController.getOutput();
    frc::SmartDashboard::PutNumber("Output", headingOutput);
    rightMaster.Power(leftHand - headingOutput);
    leftMaster.Power(leftHand + headingOutput);

    lastUpdate = chrono::high_resolution_clock::now();
    
}

void FluxChassis::autonInit() {
    ;
}

void FluxChassis::autonUpdate() {
    ;
}

void FluxChassis::disabledInit() {
    ;
}

void FluxChassis::disabledUpdate() {
    ;
}