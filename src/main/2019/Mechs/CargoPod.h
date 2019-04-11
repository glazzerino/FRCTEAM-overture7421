#pragma once
#include "Subsystems/FluxSubsystem.h"
#include "Utilities/FluxVictor.h"
#include "frc/XboxController.h"
#include "Utilities/Piston.h"
#include "frc/Solenoid.h"
#include "frc/VictorSP.h"

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
       
        frc::XboxController xbox{1};
       //6 7 lengua
       //0 1 disco
       frc::VictorSP garra2{0};
       FluxVictor garra{4};
        
        //4 macoi 
      //vic 1 ES GARRA
      //vic 0 y 5 SON CHASSIS
      bool solenoidState = true;
      
      frc::Solenoid cargoPistons{4};
      bool cargoPistonsState = true;  
        
};