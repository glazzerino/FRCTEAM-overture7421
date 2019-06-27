#include "2019/Mechs/Hatcher.h"

Hatcher::Hatcher() : FluxSubsystem("Hatcher"){

}

void Hatcher::robotInit(){
    printf("HATCHER ONLINE\n");
}

void Hatcher::robotUpdate() {

}

void Hatcher::teleopInit() {
    
}

void Hatcher::teleopUpdate() {
    updateTeleopMovement();
}

void Hatcher::disabledInit() {
   
}
void Hatcher::disabledUpdate() {

}

void Hatcher::autonInit() {

}

void Hatcher::autonUpdate() {
    updateTeleopMovement();

}
void Hatcher::updateTeleopMovement(){
    if (xbox.GetBButtonPressed()) {
        tongue.pushOrPull();
    }
    if (xbox.GetAButtonPressed()) {
        hatcherState = !hatcherState;
        hatcher.Set(hatcherState);
    }
}
