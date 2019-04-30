#pragma once
#include <iostream>
#include "Subsystems/FluxRobot.h"
#include "Subsystems/FluxChassis.h"
#include "2019/Mechs/CargoPod.h"
#include "2019/Mechs/Hatcher.h"

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
    private:
        std::shared_ptr<FluxChassis> chassis;
        std::shared_ptr<CargoPod> cargoPod;
        std::shared_ptr<Hatcher> hatcher;
};