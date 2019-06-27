#pragma once    
#include "Utilities/FluxVictor.h"
#include "Utilities/Piston.h"
using namespace std;
/**
 * Enumerator used for declaring which gear is to be used. Required by the gearMode() function.
 * Done this way to avoid the confusions the use of booleans implies.
 */
enum GEAR {
    FIRST,
    SECOND,
};

class Gearbox {
    public:
        Gearbox(unsigned int one, unsigned int two, unsigned int three);
        void power(float input);
        /**
         * To change gear one must use a value from the GEAR enumerator, either FIRST or SECOND
         */
        void gearMode(GEAR input);
        void ConfigOpenLoopRamp(float time);
        void ConfigVoltageCompSaturation(float time);
        /**
         * First integer serves as motor ID. Boolean is enabled/disabled
         */
        void motorInversion(int motor, bool setting);
    private:
        FluxVictor motorOne;
        FluxVictor motorTwo;
        FluxVictor motorThree;
        GEAR gear;

};  