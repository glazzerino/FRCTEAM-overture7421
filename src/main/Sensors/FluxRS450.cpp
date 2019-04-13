#include "Sensors/FluxRS450.h"

FluxRS450::FluxRS450(SPI::Port portID) : ADXRS450_Gyro(portID) {
    
}

void FluxRS450::setTargetHeading(double &targetHeading) {
    targetHeadingAng = targetHeading;
}

double FluxRS450::getTargetHeading() {
    return targetHeadingAng;
}