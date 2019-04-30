#include "2019/Robots/Delorean.h"

Delorean::Delorean() : FluxRobot("Delorean") {
}

void Delorean::initSubsystems() {
    cargoPod  = std::make_shared<CargoPod>();
    hatcher = std::make_shared<Hatcher>();
    chassis = std::make_shared<FluxChassis>();

    manager.addSubsystem(cargoPod);
    manager.addSubsystem(hatcher);
    manager.addSubsystem(chassis);
}

void Delorean::addProperties() {
    ;
}

void Delorean::robotInit() {
    ;
}

void Delorean::robotUpdate() {
    ;
}

void Delorean::autonInit() {
    ;
}

void Delorean::autonUpdate() {
    ;
}

void Delorean::teleopInit() {
   
    ;
}

void Delorean::teleopUpdate() {

    ;
}

void Delorean::disabledInit() {
    ;
}

void Delorean::disabledUpdate() {
    ;
}


