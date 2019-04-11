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
        FluxVictor leftMaster{0};
        FluxVictor leftSlave{5};
        FluxVictor rightMaster{1};
        FluxVictor rightSlave{3};
};