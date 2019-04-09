#include "2019/Pepito/Pepito.h"
#include "2019/Pepito/Mechs/Pepochassis.h"
#include "2019/Mechs/CargoPod.h"
#include "2019/Mechs/Hatcher.h"
Pepito::Pepito() : FluxRobot("Pepito") {
    
}

void Pepito::initSubsystems() {
    pepoChassis = std::make_shared<PepoChassis>();
    cargoPod = std::make_shared<CargoPod>();
    hatcher = std::make_shared<Hatcher>();
    manager.addSubsystem(pepoChassis);
    manager.addSubsystem(cargoPod);
    manager.addSubsystem(hatcher);
}

void Pepito::addProperties() {
    ;
}

void Pepito::robotInit() {
    std::cout << "GOT HERE" << "\n";
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


