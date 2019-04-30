#pragma once
#include "Utilities/Piston.h"
#include "Subsystems/FluxSubsystem.h"
#include "frc/XboxController.h"
class Hatcher : public FluxSubsystem {
    public:
        Hatcher();
        void robotInit() override;
        void robotUpdate() override;
        void teleopInit() override;
        void teleopUpdate() override;
        void disabledInit() override;
        void disabledUpdate() override;
        void autonInit() override;
        void autonUpdate() override;
    private:
        void updateTeleopMovement();
        Piston tongue{1,2};
        Piston hatcher{6,7};
         
        bool tongueState = false;
        bool hatcherState = false;
        frc::XboxController xbox{1};
};