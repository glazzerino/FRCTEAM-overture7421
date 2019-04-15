#include "Coprocessors/LEDS.h"

LEDS::LEDS() : FluxSubsystem("Arduino LEDS"), SerialPort(SerialPort::Port::kUSB){

}
void LEDS::robotInit() {
    ;
}

void LEDS::robotUpdate() {
    speed = datapool.getData("Odometry","linearSpeed") * 100;
}

void LEDS::teleopInit() { 
    /*packet << speed;
    SerialPort::Write(packet.str());
    packet.clear();*/
    SerialPort::Write("l",1);
}
void LEDS::teleopUpdate() {
    ;
}
void LEDS::autonInit() {
    ;
}
void LEDS::autonUpdate() {
    ;
}
void LEDS::disabledInit() {
    ;
}
void LEDS::disabledUpdate() {
    SerialPort::Write("r",1);
}