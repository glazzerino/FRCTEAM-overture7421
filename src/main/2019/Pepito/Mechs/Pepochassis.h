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
#include "Subsystems/Datapool.h"
#include "Sensors/FluxRS450.h"
#include "Utilities/FluxVictor.h"
#include <cameraserver/CameraServer.h>
#include <wpi/raw_ostream.h>
#include "networktables/NetworkTableInstance.h"
#include <chrono>


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
        void toggleHeading();
        
        float ramp = 1.0/4.0;
        Fluxcontroller xbox{0};
        frc::SPI::Port kGyroPort;
        //frc::ADXRS450_Gyro gyro;
        double leftJoystick = 0.0;
        double rightJoystick = 0.0;
        FluxVictor leftVictor{0};
        FluxVictor leftSlave{5};
        FluxVictor rightVictor{1};
        FluxVictor rightSlave{3};
        bool useJoys = true;
        bool expJoys = true;
        Datapool &datapool = Datapool::getInstance();
        FluxRS450 &gyro = FluxRS450::getInstance(kGyroPort);
      //1 ES GARRA
      // 0 5 left
      //1 3 right
      // 0 es rojo
        enum TOGGLE_HEADING{
            ENGAGED,
            DOING,
            DONE,
            IDLE
        };
        std::shared_ptr<NetworkTable> visionTable;
        TOGGLE_HEADING toggleState;
        bool swapSides = false;
        double headingOutput;
        double headingError;

        double YAW = 0.0;
        double lastYaw = 0.0;
        double yawDelta = 0.0;
        bool rampState = true;
        std::chrono::high_resolution_clock::time_point startTime;
        double nowTime;
        double lastUpdate = 0.0;
};