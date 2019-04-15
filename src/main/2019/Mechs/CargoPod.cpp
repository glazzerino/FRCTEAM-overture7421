#include "2019/Mechs/CargoPod.h"

CargoPod::CargoPod() :
    FluxSubsystem("CargoPod") {

    float ramp = 1.0/5.0;
    garra.ConfigOpenloopRamp(ramp);
   
    garra.SetNeutralMode(Brake);
}

void CargoPod::robotInit() {
    std::cout << "CARGO POD ONLINE" << "\n";
}

void CargoPod::robotUpdate() {
   frc::SmartDashboard::PutBoolean("cargoPistons",cargoPistons.Get());
}

void CargoPod::teleopInit() {
    //cargoPistons.Set(false);
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
   /* if (!cargoPistons.Get()){
         cargoPistons.Set(true);
    }*/
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
    if (xbox.GetXButtonPressed()) {
        habState = !habState;
        habPiston.Set(habState);
    }
    
}
