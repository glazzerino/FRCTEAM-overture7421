#include "Utilities/FluxVictor.h"

FluxVictor::FluxVictor(unsigned int port) : VictorSPX(port),  BaseMotorController(port | 0x1040000) {}

void FluxVictor::Power(double input) {
    if (setNegateBool) {
        input = -input;
    }
    VictorSPX::Set(ControlMode::PercentOutput, input);
}

void FluxVictor::Brake() {
    VictorSPX::Set(ControlMode::PercentOutput, 0.0);
}
