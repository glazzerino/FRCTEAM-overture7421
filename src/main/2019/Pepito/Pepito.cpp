#include "2019/Pepito/Pepito.h"

#include "2019/Mechs/CargoPod.h"
#include "2019/Mechs/Hatcher.h"
Pepito::Pepito() : FluxRobot("Pepito") {
    
}

void Pepito::initSubsystems() {
   
    cargoPod = std::make_shared<CargoPod>();
    hatcher = std::make_shared<Hatcher>();
    
    manager.addSubsystem(cargoPod);
    manager.addSubsystem(hatcher);
}

void Pepito::addProperties() {
    ;
}

void Pepito::robotInit() {
    std::cout << "INITIATED\n";
}

void Pepito::robotUpdate() {
    ;
}

void Pepito::autonInit() {
    ;
}

void Pepito::autonUpdate() {
    ;
}

void Pepito::teleopInit() {
   
    ;
}

void Pepito::teleopUpdate() {
    ;
}

void Pepito::disabledInit() {
    ;
}

void Pepito::disabledUpdate() {
    ;
}


