#pragma once
#include "Subsystems/FluxSubsystem.h"
#include "Utilities/FluxVictor.h"
#include "frc/XboxController.h"
#include "Utilities/Piston.h"
#include "frc/Solenoid.h"
#include "frc/VictorSP.h"
#include "Subsystems/Datapool.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "Utilities/Piston.h"
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
        void updateTeleopMovement();
        Datapool &datapool = Datapool::getInstance();
        frc::XboxController xbox{1};
        FluxVictor garra2{4};
        FluxVictor garra{8};
        bool solenoidState = true;
        frc::Solenoid cargoPistons{4};
        bool cargoPistonsState = false;  
        bool done = false;
};