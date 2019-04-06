#include "Subsystems/SubsystemManager.h"
#include "frc/Timer.h"
SubsystemManager::SubsystemManager() {
    std::cout << "Subsystem manager started" << "\n";
}
/**
 * Adds a subsystem to the queue, respective function of subsystem will be executed
 */

void SubsystemManager::addSubsystem(const shared_ptr<FluxSubsystem> &newSys) {
    if (newSys == nullptr) {
        throw std::runtime_error("Subsystem pointer is null");
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
       // std::cout << "Time taken by susbystem "<< subsystem ->getName() << ": " <<
        //frc::Timer::GetFPGATimestamp() - currentTime << "\n"; 
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
