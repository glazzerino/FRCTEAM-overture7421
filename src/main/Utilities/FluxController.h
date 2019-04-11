#include "frc/XboxController.h"
#include <cmath>
using namespace frc;

/**
 * This class adds some overture goodies to input mode
 * */
class Fluxcontroller : public frc::XboxController {
    public:
        Fluxcontroller(unsigned int USBPort);
        double joystick(GenericHID::JoystickHand);
        void setExpJoystick(bool input);
    private:
        bool expJoystickBool = false;
};



