#pragma once
#include "Subsystems/FluxSubsystem.h"
#include "ctre/Phoenix.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <cmath>
#include "frc/XboxController.h"
#include "frc/ADXRS450_Gyro.h"
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
       /* VictorSPX leftVictor{1};
        VictorSPX rightVictor{2};
        VictorSPX leftSlave{3};
        VictorSPX rightSlave{4};*/
        
};