#include "2019/Mechs/Hatcher.h"

Hatcher::Hatcher() : FluxSubsystem("Hatcher"){

}

void Hatcher::robotInit(){
    printf("HATCHER ONLINE\n");
}

void Hatcher::robotUpdate() {

}

void Hatcher::teleopInit() {
    tongue.Project();
}

void Hatcher::teleopUpdate() {
    if (xbox.GetBButtonPressed()) {

        //tongue.Set(frc::DoubleSolenoid::kForward);
    }
}

void Hatcher::disabledInit() {
   
}
void Hatcher::disabledUpdate() {

}

void Hatcher::autonInit() {

}

void Hatcher::autonUpdate() {

}