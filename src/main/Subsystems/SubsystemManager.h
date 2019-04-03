#pragma once
#include "Subsystems/FluxSubsystem.h"
#include <memory>
#include <vector>
class FluxSubsystem;

class SubsystemManager {
    public:
        static SubsystemManager &getInstance() {
            static SubsystemManager uniqueInstance;
            return uniqueInstance;
        }
       
        void addSubsystem(const std::shared_ptr<FluxSubsystem> &newSys);

        void robotInit();
        void robotUpdate();

        void teleopInit();
        void teleopUpdate();

        void autonInit();
        void autonUpdate();

        void disableInit();
        void disableUpdate();
        
  private:
    SubsystemManager();
    bool managerStatus = false;
    std::vector<shared_ptr<FluxSubsystem>> subsystems;
};