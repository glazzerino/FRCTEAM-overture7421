#include "2019/Mechs/CargoPod.h"

CargoPod::CargoPod() :
FluxSubsystem("CargoPod") {
    
    float ramp = 1.0/4.0;
    garra.ConfigOpenloopRamp(ramp);
    garra2.ConfigOpenloopRamp(ramp);
    garra2.SetNeutralMode(Coast);
    garra.SetNeutralMode(Coast);
}

void CargoPod::robotInit() {
    std::cout << "CARGO ONLINE" << "\n";
    garra2.ConfigVoltageCompSaturation(12.0,12.0);
    garra.ConfigVoltageCompSaturation(12.0,12.0);
    garra2.EnableVoltageCompensation(true);
    garra.EnableVoltageCompensation(true);
}

void CargoPod::robotUpdate() {
   /*garra.Set(ControlMode::PercentOutput, leftJoystick);
   garra2.Set(ControlMode::PercentOutput, leftJoystick);*/
}
    
void CargoPod::teleopInit() {
    
}

void CargoPod::teleopUpdate() {
    garra.Set(ControlMode::PercentOutput, xbox.GetY(frc::XboxController::kLeftHand));
    garra2.Set(ControlMode::PercentOutput, -xbox.GetY(frc::XboxController::kLeftHand));
}

void CargoPod::autonInit(){
    ;
}

void CargoPod::autonUpdate() {
    ;
}

void CargoPod::disabledInit() {
    ;
}

void CargoPod::disabledUpdate() {
    ;
}
