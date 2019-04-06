#pragma once
#include "Subsystems/FluxSubsystem.h"
#include "ctre/Phoenix.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <cmath>
#include "frc/XboxController.h"
#include "frc/ADXRS450_Gyro.h"
#include "Subsystems/DataPool.h"
#include "frc/VictorSP.h"
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
        frc::XboxController xbox{0};
        frc::SPI::Port kGyroPort;
        frc::ADXRS450_Gyro gyro;
        double leftJoystick ,rightJoystick = 0.0;
        VictorSPX leftVictor{0};
        VictorSPX rightVictor{5};
        frc::VictorSP leftSlave{0};
        frc::VictorSP rightSlave{1};
        bool useJoys = true;
      //1 ES GARRA
      // 0 y 5 SON CHASSIS
 
        
};