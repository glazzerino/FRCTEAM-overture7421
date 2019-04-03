#include "2019/Pepito/Mechs/Pepochassis.h"

PepoChassis::PepoChassis() :
FluxSubsystem("Pepochassis") {
    /*leftSlave.Set(ControlMode::Follower, leftVictor.GetDeviceID());
    rightSlave.Set(ControlMode::Follower, rightVictor.GetDeviceID());
    float ramp = 1.0/3.0;
    leftVictor.ConfigOpenloopRamp(ramp);
    rightVictor.ConfigOpenloopRamp(ramp);*/
}

void PepoChassis::robotInit() {
    std::cout << "PEPO ONLINE" << "\n";
    /*rightVictor.ConfigVoltageCompSaturation(12.0,12.0);
    leftVictor.ConfigVoltageCompSaturation(12.0,12.0);
    rightVictor.EnableVoltageCompensation(true);
    leftVictor.EnableVoltageCompensation(true);
    std::cout << "PEPITO IS ONLINE" << "\n";*/
}

void PepoChassis::robotUpdate() {
    if (xbox.GetY(frc::XboxController::kLeftHand) < 0.02) {
        leftJoystick = 0.0;
    }
    if (xbox.GetY(frc::XboxController::kLeftHand) < 0.02) {
        rightJoystick = 0.0;
    }
    leftJoystick = xbox.GetY(frc::XboxController::kLeftHand);
    rightJoystick = xbox.GetY(frc::XboxController::kRightHand);
}

void PepoChassis::teleopInit() {
    std::cout << "TELEOP ENABLED" << "\n";
}

void PepoChassis::teleopUpdate() {
    /*leftVictor.Set(ControlMode::PercentOutput, leftJoystick);
    rightVictor.Set(ControlMode::PercentOutput, rightJoystick);*/
    if (xbox.GetAButton()) {
        frc::SmartDashboard::PutBoolean("BUTTON", true);
    } else {
        frc::SmartDashboard::PutBoolean("BUTTON", false);
    }
}

void PepoChassis::autonInit(){
    ;
}

void PepoChassis::autonUpdate() {
    ;
}

void PepoChassis::disabledInit() {
    ;
}

void PepoChassis::disabledUpdate() {
    ;
}
