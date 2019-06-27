#pragma once
#include "ctre/Phoenix.h"
/**
 * Wrapper for VictorSPX, because syntax sugar.
 */
class FluxVictor : public VictorSPX {
    public:
        FluxVictor(unsigned int port);
        void Power(double input);
        void Brake();
    private:
        bool setNegateBool = false;
};