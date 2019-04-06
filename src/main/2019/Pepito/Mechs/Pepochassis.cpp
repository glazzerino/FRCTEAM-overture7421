#include "2019/Pepito/Mechs/Pepochassis.h"

PepoChassis::PepoChassis() :
FluxSubsystem("Pepochassis") {
    /*leftSlave.Set(ControlMode::Follower, leftVictor.GetDeviceID());
    rightSlave.Set(ControlMode::Follower, rightVictor.GetDeviceID());*/
    float ramp = 1.0/4.0;
    //leftVictor.ConfigOpenloopRamp(ramp);
    //rightVictor.ConfigOpenloopRamp(ramp);
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
   /*leftVictor.Set(ControlMode::PercentOutput, leftJoystick);
   rightVictor.Set(ControlMode::PercentOutput, leftJoystick);*/
}
    
void PepoChassis::teleopInit() {
    std::cout << "TELEOP ENABLED" << "\n";
}

void PepoChassis::teleopUpdate() {
    leftVictor.Set(ControlMode::PercentOutput, -xbox.GetY(frc::XboxController::kLeftHand));
    leftSlave.Set(-xbox.GetY(frc::XboxController::kLeftHand));
    rightVictor.Set(ControlMode::PercentOutput, xbox.GetY(frc::XboxController::kRightHand));
    rightSlave.Set( xbox.GetY(frc::XboxController::kRightHand));
    /*rightVictor.Set(ControlMode::PercentOutput, rightJoystick);
    if (xbox.GetAButton()) {
        frc::SmartDashboard::PutBoolean("BUTTON", true);
    } else {
        frc::SmartDashboard::PutBoolean("BUTTON", false);
    }
    cout << leftJoystick  << " " << rightJoystick<< "\n";
*/
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
