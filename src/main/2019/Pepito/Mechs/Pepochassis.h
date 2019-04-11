#pragma once
#include "Subsystems/FluxSubsystem.h"
#include "ctre/Phoenix.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <cmath>
#include "frc/XboxController.h"
#include "frc/ADXRS450_Gyro.h"
#include "Subsystems/Datapool.h"
#include "frc/VictorSP.h"
#include "Utilities/Piston.h"
#include "Utilities/FluxController.h"

class PepoChassis : public FluxSubsystem {
    public:
        PepoChassis();

        void robotInit() override;
        void robotUpdate() override;

        void teleopInit() override;
        void teleopUpdate() override;

        void autonInit() override;
        void autonUpdate() override;
        
        void disabledInit() override;
        void disabledUpdate() override;

    private:
        
         enum NITRO_STATE{
                ENABLED,
                DISABLED
            };
        NITRO_STATE nitroState = DISABLED;
        float ramp = 1.0/4.0;
        Fluxcontroller xbox{0};
        frc::SPI::Port kGyroPort;
        frc::ADXRS450_Gyro gyro;
        double leftJoystick = 0.0;
        double rightJoystick = 0.0;
        VictorSPX leftVictor{0};
        VictorSPX leftSlave{5};
        VictorSPX rightVictor{1};
        VictorSPX rightSlave{3};
        bool useJoys = true;

      //1 ES GARRA
      // 0 y 5 SON CHASSIS
      // 0 es rojo
      // 
 
        
};