#include "Subsystems/FluxSubsystem.h"

FluxSubsystem::FluxSubsystem(const std::string &name) {
    this->name = name;
}

void FluxSubsystem::robotInit() {
    ;
}

void FluxSubsystem::robotUpdate() {
    ;
}

void FluxSubsystem::teleopInit() {
    ;
}

void FluxSubsystem::teleopUpdate() {
    ;
}

void FluxSubsystem::autonInit() {
    ;
}

void FluxSubsystem::autonUpdate() {
    ;
}

void FluxSubsystem::disabledInit() {
    ;
}

void FluxSubsystem::disabledUpdate() {
    ;
}

std::string FluxSubsystem::getName() const {
    return name;
}