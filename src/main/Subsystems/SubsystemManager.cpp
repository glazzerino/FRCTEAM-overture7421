#include "Subsystems/SubsystemManager.h"
#include <frc/Timer.h>

SubsystemManager::SubsystemManager() {

}

void SubsystemManager::addSubsystem(const shared_ptr<FluxSubsystem> &newSys) {
    if (newSys == nullptr) {
        //thow std::runtime_error("")
    }
    subsystems.emplace_back(newSys);
}

void SubsystemManager::robotInit() {
    for (const auto &subsystem : subsystems) {
        subsystem -> robotInit();
    }
}

void SubsystemManager::robotUpdate() {
    for (const auto &subsystem : subsystems) {
        double currentTime = frc::Timer::GetFPGATimestamp();
        subsystem -> robotUpdate();
    }
}

void SubsystemManager::teleopInit() {
    for (const auto &subsystem : subsystems) {
        subsystem -> teleopInit();
    }
}

void SubsystemManager::teleopUpdate() {
    for (const auto &subsystem : subsystems) {
        subsystem -> teleopUpdate();
    }
}

void SubsystemManager::autonInit() {
    for (const auto &subsystem : subsystems) {
        subsystem -> autonInit();
    }
}

void SubsystemManager::autonUpdate() {
    for (const auto &subsystem : subsystems) {
        subsystem -> autonUpdate();
    }
}

void SubsystemManager::disableInit() {
    for (const auto &subsystem : subsystems) {
        subsystem -> disabledInit();
    }
}

void SubsystemManager::disableUpdate() {
    for (const auto &subsystem : subsystems) {
        subsystem -> disabledUpdate();
    }
}
