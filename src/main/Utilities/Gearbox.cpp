#include "Utilities/Gearbox.h"

Gearbox::Gearbox(unsigned int one, unsigned int two, unsigned int three): motorOne(one), 
motorTwo(two), motorThree(three) {
    motorTwo.Set(ControlMode::Follower,motorOne.GetDeviceID());
    motorThree.Set(ControlMode::Follower,motorOne.GetDeviceID());
    motorOne.SetNeutralMode(NeutralMode::Brake);
    motorTwo.SetNeutralMode(NeutralMode::Brake);
    motorThree.SetNeutralMode(NeutralMode::Brake);
}

void Gearbox::power(float s) {
    motorOne.Power(s);
}

void Gearbox::gearMode(GEAR s) {
    switch (s) {
        case GEAR::FIRST:
            gear = GEAR::FIRST;
            break;
        case GEAR::SECOND:
            gear = GEAR::SECOND;
            break;
    }
}

void Gearbox::ConfigOpenLoopRamp(float time) {
    motorOne.ConfigOpenloopRamp(time);
    motorTwo.ConfigOpenloopRamp(time);
    motorThree.ConfigOpenloopRamp(time);
}

void Gearbox::ConfigVoltageCompSaturation(float time) {
    motorOne.ConfigVoltageCompSaturation(time);
    motorOne.EnableVoltageCompensation(true);
    motorTwo.ConfigVoltageCompSaturation(time);
    motorTwo.ConfigVoltageCompSaturation(true);
    motorThree.ConfigVoltageCompSaturation(time);
    motorThree.EnableVoltageCompensation(true);
}

void Gearbox::motorInversion(int motor, bool setting) {
    switch (motor) {
        case 1:
            motorOne.SetInverted(setting);
            break;
        case 2: 
            motorTwo.SetInverted(setting);
        case 3:
            motorThree.SetInverted(setting);
    }
}

