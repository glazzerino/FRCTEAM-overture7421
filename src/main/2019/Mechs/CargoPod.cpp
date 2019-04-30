#include "2019/Mechs/CargoPod.h"

CargoPod::CargoPod() :
    FluxSubsystem("CargoPod") {
    float ramp = 1.0/5.0;
    garra.ConfigOpenloopRamp(ramp);
    garra2.SetInverted(true);
    garra.SetNeutralMode(Brake);
}

void CargoPod::robotInit() {
   
    std::cout << "CARGO POD ONLINE" << "\n";
    cargoPistons.Set(false);
    
}

void CargoPod::robotUpdate() {
   frc::SmartDashboard::PutBoolean("cargoPistons",cargoPistons.Get());
}

void CargoPod::teleopInit() {
;
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
   if (!done) {
        cargoPistons.Set(false);
        
   }
  
}

void CargoPod::updateTeleopMovement(){
    garra.Set(ControlMode::PercentOutput, xbox.GetY(frc::XboxController::kLeftHand));
    garra2.Set(ControlMode::PercentOutput,xbox.GetY(frc::XboxController::kRightHand));
    //std::cout << "cargo piston: " << cargoPistons.Get() << " habPistons: " << habPiston.Get() <<"\n";
    if (xbox.GetYButtonPressed()) {
        cargoPistons.Set(!cargoPistons.Get());
    }
    if (xbox.GetXButtonPressed()) {
       habPiston.pushOrPull();
    }
}
