#include "2019/Pepito/Mechs/Pepochassis.h"

PepoChassis::PepoChassis(unsigned int leftSlaveP, unsigned int leftVictorP, unsigned int rightSlaveP, unsigned int rightVictorP, double ramp) :
FluxSubsystem("Pepochassis"), leftSlave(leftSlaveP), leftVictor(leftVictorP), 
rightSlave(rightSlaveP), rightVictor(rightVictorP) {
    leftSlave.Set(ControlMode::Follower, leftVictor.GetDeviceID());
    rightSlave.Set(ControlMode::Follower, rightVictor.GetDeviceID());
    leftVictor.ConfigOpenloopRamp(ramp);
    rightVictor.ConfigOpenloopRamp(ramp);
}

void PepoChassis::robotInit() {
    rightVictor.ConfigVoltageCompSaturation(12.0,12.0);
    leftVictor.ConfigVoltageCompSaturation(12.0,12.0);
    rightVictor.EnableVoltageCompensation(true);
    leftVictor.EnableVoltageCompensation(true);
    std::cout << "PEPITO IS ONLINE" << "\n";
}

void PepoChassis::robotUpdate() {
    if (xbox.GetY(frc::XboxController::kLeftHand) < 0.03) {
        leftJoystick = 0.0;
    }
    if (xbox.GetY(frc::XboxController::kLeftHand) < 0.03) {
        rightJoystick = 0.0;
    }
}

void PepoChassis::teleopInit() {
    std::cout << "TELEOP ENABLED" << "\n";
}

void PepoChassis::teleopUpdate() {
    leftVictor.Set(ControlMode::PercentOutput,  leftJoystick);
    rightVictor.Set(ControlMode::PercentOutput, rightJoystick);
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
