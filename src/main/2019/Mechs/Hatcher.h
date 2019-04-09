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
        Piston tongue{6,7};
        
        frc::XboxController xbox{1};
};