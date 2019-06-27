#pragma once
#include "PID/PID.h"
#include "Subsystems/FluxSubsystem.h"
#include "Utilities/FluxVictor.h"
#include "AHRS.h"
#include "frc/XboxController.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <chrono>
#include "networktables/NetworkTableInstance.h"
#include "Utilities/Gearbox.h"
#include "frc/Compressor.h"
using namespace std;


class FluxChassis : public FluxSubsystem {
    public:
        FluxChassis();
       
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
        Gearbox leftGear{9,6,2};
        Gearbox rightGear{3,1,7};
        Piston gearPiston{6,7};
        AHRS navx{SPI::Port::kMXP};
        PID headingController;
        double headingTarget = 0.0;
        double maxAngularVelocity = 180.0;
        chrono::high_resolution_clock::time_point lastUpdate = chrono::high_resolution_clock::now();
        double ramp = 1.0/4.0;
        double targetYaw = 0.0;
        std::shared_ptr<NetworkTable> visionTable;
        bool visionEngaged = false;
        double maxAngularVelocityVision = 0.0;
        frc::Compressor compressor;
       
};
