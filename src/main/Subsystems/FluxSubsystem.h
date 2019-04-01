#pragma once
#include  <string>
#include <memory>
#include <iostream>
using namespace std;
/**
 * This class is to be used on any subsystem to be implemented on the robot.
 * Functions must be filled when implemented at subsystem writing.
 * Follows TimedRobot's structure
 */ 
class FluxSubsystem {

    public:
        explicit FluxSubsystem(const std::string &name);

        virtual void robotInit();
        virtual void robotUpdate();

        virtual void teleopInit();
        virtual void teleopUpdate();

        virtual void autonInit();
        virtual void autonUpdate();

        virtual void disabledInit();
        virtual void disabledUpdate();

        std::string getName() const;
        
    private:
        std::string name;
};