#include "2019/Mechs/DriveTrain.h"

Drivetrain::Drivetrain() : FluxSubsystem("Drivetrain") {
    rightSlave.Set(ControlMode::Follower, rightMaster.GetDeviceID());
}

void Drivetrain::autonInit() {
    ;     
}

void Drivetrain::autonUpdate() {
    ; 
}

void Drivetrain::robotInit(){
    ;
}

void Drivetrain::robotUpdate() {
    ;
}

void Drivetrain::teleopInit() {
    ;
}

void Drivetrain::teleopUpdate() {
    ;
}

void Drivetrain::disabledInit() {
    ;
}

void Drivetrain::disabledUpdate() {
    ;
}