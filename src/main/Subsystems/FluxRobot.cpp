#include "Subsystems/FluxRobot.h"

FluxRobot::FluxRobot(const std::string &robotName) : TimedRobot(), 
    FluxSubsystem(robotName){
}

void FluxRobot::RobotInit() {
    this->addProperties();
    this->initSubsystems();
    this->robotInit();
    manager.robotInit();
}

void FluxRobot::RobotPeriodic() {
    this->robotUpdate();
    manager.robotUpdate();
}

void FluxRobot::DisabledInit() {
    this->disabledInit();
    manager.disableInit();
}

void FluxRobot::DisabledPeriodic() {
    this->disabledUpdate();
    manager.disableUpdate();
}

void FluxRobot::TeleopInit() {
    this-> teleopInit();
    manager.teleopInit();
}

void FluxRobot::TeleopPeriodic() {
    this-> teleopUpdate();
    manager.teleopUpdate();
}

void FluxRobot::AutonomousInit() {
    this->autonInit();
    manager.autonInit();
}

void FluxRobot::AutonomousPeriodic() {
    this-> autonUpdate();
    manager.autonUpdate();
}