#include "frc/XboxController.h"

enum HAND {
    LEFT,
    RIGHT
};

struct AnalogStates {
    bool leftTriggerPressed;
    bool rightTriggerPressed;
    double leftJoystic;
    double rightJoystick;
};

/**
 * This class wraps XboxController to add trigger activation booleans.
 * This class is built to be applied to a subsystem.
 * NOTE: Future version will be a susbsytem of it's own
 */
class Fluxcontroller : public frc::XboxController {
    public:
        Fluxcontroller(unsigned int USBPort);
        bool triggerPressed(HAND hand);
        bool triggerReleased(HAND hand);
        void updateInputs();
    private:
        bool lastStateWasPressed = false;
        AnalogStates analogStates;
        bool previousLeftTrigger = false;
        bool previousRightTrigger = false;
        bool leftWasReleased = false;
        bool rightWasReleased = false;
};



