#pragma once
#include "Subsystems/FluxSubsystem.h"
#include "Utilities/FluxVictor.h"
#include "frc/XboxController.h"

class CargoPod : public FluxSubsystem {
    public:
        CargoPod();

        void robotInit() override;
        void robotUpdate() override;

        void teleopInit() override;
        void teleopUpdate() override;

        void autonInit() override;
        void autonUpdate() override;
        
        void disabledInit() override;
        void disabledUpdate() override;

    private:
        frc::XboxController xbox{1};
        FluxVictor garra{1};
        FluxVictor garra2{4};
      //1 ES GARRA
      // 0 y 5 SON CHASSIS
 
        
};