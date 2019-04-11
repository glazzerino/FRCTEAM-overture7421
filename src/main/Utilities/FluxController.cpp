#include "Utilities/FluxController.h"
using namespace frc;
Fluxcontroller::Fluxcontroller(unsigned int USBPort) : XboxController(USBPort){

}

void Fluxcontroller::setExpJoystick(bool input) {
    if(input) {
        expJoystickBool = true;
    } else {
        expJoystickBool = false;
    }
}


double Fluxcontroller::joystick(GenericHID::JoystickHand hand) {
    double output = XboxController::GetY(hand);
    double multiplier = 1.0;
    if (expJoystickBool) {
        if (output < 0.0) {
            multiplier = -multiplier;
        }
        return pow(XboxController::GetY(hand),2) * multiplier;
    }
}