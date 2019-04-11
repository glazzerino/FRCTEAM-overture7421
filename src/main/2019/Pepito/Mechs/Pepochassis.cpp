#include "2019/Pepito/Mechs/Pepochassis.h"

PepoChassis::PepoChassis() :
FluxSubsystem("Pepochassis") {
    leftSlave.Set(ControlMode::Follower, leftVictor.GetDeviceID());
    rightSlave.Set(ControlMode::Follower, rightVictor.GetDeviceID());
    
    leftVictor.ConfigOpenloopRamp(ramp);
    rightVictor.ConfigOpenloopRamp(ramp);
    rightVictor.SetNeutralMode(Brake);
    leftVictor.SetNeutralMode(Brake);
}

void PepoChassis::robotInit() {
    rightVictor.ConfigVoltageCompSaturation(12.0,12.0);
    leftVictor.ConfigVoltageCompSaturation(12.0,12.0);
    rightVictor.EnableVoltageCompensation(true);
    leftVictor.EnableVoltageCompensation(true);
    
     std::cout << "PEPITO IS ONLINE" << "\n";
    }
   


void PepoChassis::robotUpdate() {
    if (xbox.GetY(frc::XboxController::kLeftHand) > 0.0) {
        leftJoystick = powf(xbox.GetY(frc::XboxController::kLeftHand),2);
    } else {
        leftJoystick = powf(xbox.GetY(frc::XboxController::kLeftHand),2) * -1;
    }
    if (xbox.GetY(frc::XboxController::kRightHand) > 0.0) {
        rightJoystick = powf(xbox.GetY(frc::XboxController::kRightHand),2);
    } else {
         rightJoystick = powf(xbox.GetY(frc::XboxController::kRightHand),2) * -1;
    }

    leftJoystick = xbox.GetY(frc::XboxController::kLeftHand);
    rightJoystick = xbox.GetY(frc::XboxController::kRightHand);
}
    
void PepoChassis::teleopInit() {
    printf("TELEOP STARTED\n");
}

void PepoChassis::teleopUpdate() {
    
    rightVictor.Set(ControlMode::PercentOutput, -leftJoystick);
    leftVictor.Set(ControlMode::PercentOutput, rightJoystick);
    if (xbox.GetStartButtonReleased()) {
        switch (nitroState) {
            case NITRO_STATE::ENABLED:
                frc::SmartDashboard::PutBoolean("NITRO", false);
                nitroState = NITRO_STATE::DISABLED;
                rightVictor.ConfigOpenloopRamp(0.0);
                leftVictor.ConfigOpenloopRamp(0.0);
                break;
            case NITRO_STATE::DISABLED:
                frc::SmartDashboard::PutBoolean("NITRO", true);
                    nitroState = NITRO_STATE::ENABLED;
                    rightVictor.ConfigOpenloopRamp(ramp);
                    leftVictor.ConfigOpenloopRamp(ramp);
        }
    }
    
    if (xbox.GetAButton()) {
        frc::SmartDashboard::PutBoolean("BUTTON", true);
    } else {
        frc::SmartDashboard::PutBoolean("BUTTON", false);
    }
    cout << leftJoystick  << " " << rightJoystick<< "\n";


}

void PepoChassis::autonInit(){
    ;
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


