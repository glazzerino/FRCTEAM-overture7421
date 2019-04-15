#pragma once
#include "frc/SerialPort.h"
#include "Subsystems/FluxSubsystem.h"
#include "Subsystems/Datapool.h"
#include <sstream>
using namespace frc;
class LEDS: public FluxSubsystem, public SerialPort {
    public:
        LEDS();
        void robotInit() override;
        void robotUpdate() override;
        void teleopInit() override;
        void teleopUpdate() override;
        void autonInit() override;
        void autonUpdate() override;
        void disabledInit() override;
        void disabledUpdate() override;
    private:
        Datapool &datapool = Datapool::getInstance();
        double speed = 0.0;
        std::stringstream packet;
};
