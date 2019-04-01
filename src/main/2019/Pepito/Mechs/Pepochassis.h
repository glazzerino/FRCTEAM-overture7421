#pragma once
#include "Subsystems/FluxSubsystem.h"
#include "ctre/Phoenix.h"
#include <cmath>
#include "frc/XboxController.h"
#include "frc/ADXRS450_Gyro.h"
class PepoChassis : public FluxSubsystem {
    public:
        PepoChassis(unsigned int vicPortLeft,unsigned int vicSlaveLeft,
        unsigned int vicSlaveRight, unsigned int vicPortRight, double ramp);

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
        VictorSPX leftVictor;
        VictorSPX rightVictor;
        VictorSPX leftSlave;
        VictorSPX rightSlave;
};