#include "Utilities/FluxController.h"
using namespace frc;
Fluxcontroller::Fluxcontroller(unsigned int USBPort) : frc::XboxController(USBPort){
    
}

bool Fluxcontroller::triggerPressed(HAND hand) {
    switch (hand) {
        case RIGHT:
            return analogStates.rightTriggerPressed;
            break;
        case LEFT:
            return analogStates.leftTriggerPressed;
            break;
    }
}


void Fluxcontroller::updateInputs() {
    if (XboxController::GetTriggerAxis(kLeftHand) != 0.0 && !previousLeftTrigger) {
        analogStates.leftTriggerPressed = true;
        previousLeftTrigger = true;
        leftWasReleased = false;
    } else if (previousLeftTrigger && XboxController::GetTriggerAxis(kLeftHand) == 0.0) {
        leftWasReleased = true;
        previousLeftTrigger = false;
    }
    if (XboxController::GetTriggerAxis(kRightHand) != 0.0 && !previousRightTrigger) {
        analogStates.rightTriggerPressed = true;
        previousRightTrigger = true;
        rightWasReleased = false;
    } else if (previousRightTrigger && XboxController::GetTriggerAxis(kRightHand) == 0.0) {
        rightWasReleased = true;
        previousRightTrigger = false;
    }
}