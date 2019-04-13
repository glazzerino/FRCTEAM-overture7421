#pragma once
#include "frc/ADXRS450_Gyro.h"
using namespace frc;
/**
 * Singleton class for ADXRS450 Gyro
 * */
class FluxRS450 : public ADXRS450_Gyro {
    private:
        explicit FluxRS450(SPI::Port portID);
        FluxRS450(const FluxRS450 &);
        FluxRS450 &operator=(const FluxRS450 &);
         double targetHeadingAng = 0.0;
    public:
        static FluxRS450 &getInstance(SPI::Port portID) {
            static FluxRS450 instance(portID);
            return instance;
        }
        void setTargetHeading(double &targetHeading);
        double getTargetHeading();
};