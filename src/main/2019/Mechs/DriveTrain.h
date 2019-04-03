#pragma once
#include "Subsystems/FluxSubsystem.h"
#include "Utilities/FluxController.h"
#include "Utilities/FluxVictor.h"
class Drivetrain : public FluxSubsystem {
    public:
        Drivetrain();
        void robotInit() override;
        void robotUpdate() override;
        void teleopInit() override;
        void teleopUpdate() override;
        void autonInit() override;
        void autonUpdate() override;
        void disabledInit() override;
        void disabledUpdate() override;

    private:
        FluxVictor leftMaster{1};
        FluxVictor rightMaster{2};
        FluxVictor leftSlave{3};
        FluxVictor rightSlave{4};
        Fluxcontroller controller{0};
};