#include "2019/Mechs/CargoPod.h"

CargoPod::CargoPod() :
    FluxSubsystem("CargoPod") {

    float ramp = 1.0/4.0;
    garra.ConfigOpenloopRamp(ramp);
   
    garra.SetNeutralMode(Brake);
}

void CargoPod::robotInit() {
    std::cout << "CARGO ONLINE" << "\n";
    
    garra.ConfigVoltageCompSaturation(12.0,12.0);
   
    garra.EnableVoltageCompensation(true);
}

void CargoPod::robotUpdate() {
   
}

void CargoPod::teleopInit() {

}

void CargoPod::teleopUpdate() {
    updateTeleopMovement();
}


void CargoPod::autonInit() {
    ;
}

void CargoPod::autonUpdate() {
    updateTeleopMovement();

}

void CargoPod::disabledInit() {
    ;
}

void CargoPod::disabledUpdate() {
    ;
}

void CargoPod::updateTeleopMovement(){
    garra.Set(ControlMode::PercentOutput, xbox.GetY(frc::XboxController::kLeftHand));
    garra2.Set(xbox.GetY(frc::XboxController::kRightHand));

    if (xbox.GetYButtonPressed()) {
        solenoidState = !solenoidState;
        cargoPistons.Set(solenoidState);
    }
}
