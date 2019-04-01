#pragma once
#include "frc/WPILib.h"
#include "Subsystems/FluxSubsystem.h"
#include "Subsystems/SubsystemManager.h"
#include <string>

    class FluxRobot : public frc::TimedRobot, protected FluxSubsystem {
    
    public:
        explicit FluxRobot(const std::string &robotName);
    /**
     * Add subsystems here 
     */
    virtual void initSubsystems() = 0;

    virtual void addProperties() = 0;
    
    protected:

        SubsystemManager &manager = SubsystemManager::getInstance();


    private:
        void RobotInit() override;

        void RobotPeriodic() override;

        void DisabledInit() override;

        void DisabledPeriodic() override;

        void TeleopInit() override;

        void TeleopPeriodic() override;

        void AutonomousInit() override;

        void AutonomousPeriodic() override;
};