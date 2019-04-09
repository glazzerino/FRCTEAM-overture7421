#pragma once
#include "frc/DoubleSolenoid.h"

using namespace frc;
class Piston : DoubleSolenoid {
    public:
        Piston(unsigned int port1, unsigned int port2) : DoubleSolenoid(port1, port2) {
            
        }
        void pushOrPull() {
            switch(state) {
                case true:
                    DoubleSolenoid::Set(DoubleSolenoid::kForward);
                    state = false;
                    break;
                case false:
                    DoubleSolenoid::Set(DoubleSolenoid::kReverse);
                    state = true;
                    break;
            }
        }

        void Project(){
            DoubleSolenoid::Set(DoubleSolenoid::kForward);
        }
        void Retract() {
            DoubleSolenoid::Set(DoubleSolenoid::kReverse);
        }
        void Off() {
            DoubleSolenoid::Set(DoubleSolenoid::kOff);
        }
    private:
        bool state;
};