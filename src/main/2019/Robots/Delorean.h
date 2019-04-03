#pragma once
#include <iostream>
#include "Subsystems/FluxRobot.h"
#include "2019/Mechs/DriveTrain.h"

class Delorean : public FluxRobot {

    public:
        Delorean();

        void addProperties() override;
        void initSubsystems() override;

        void robotInit() override;
        void robotUpdate() override;

        void teleopInit() override;
        void teleopUpdate() override;

        void autonInit() override;
        void autonUpdate() override;

        void disabledInit() override;
        void disabledUpdate() override;
};