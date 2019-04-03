#include "2019/Pepito/Pepito.h"
#include "2019/Pepito/Mechs/Pepochassis.h"
Pepito::Pepito() : FluxRobot("Pepito") {
    
}

void Pepito::initSubsystems() {
    pepoChassis = std::make_shared<PepoChassis>();
    manager.addSubsystem(pepoChassis);
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


