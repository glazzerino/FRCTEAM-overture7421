#include "PID/PID.h"

PID::PID(){
    thread PIDThread(&PID::controlLoop, this);
    PIDThread.detach();
}

void PID::controlLoop() {
    while (true) {
        double timeStep = chrono::duration<double>(chrono::high_resolution_clock::now() - lastUpdateTag).count();
        double currentError = target.load() - feedback.load(); 
        double eDelta =  (currentError - lastError) / timeStep;
        integral += currentError * timeStep;
        double currentOutput = (currentError * kP) + (integral * kI) + (eDelta * kD);
        output.store(currentOutput);
        lastError = currentError;
        lastUpdateTag = chrono::high_resolution_clock::now();

        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

void PID::setTarget(double input) {
    target.store(input);
}

void PID::setFeedback(double feedback) {
    this -> feedback.store(feedback);
}

double PID::getOutput() {
    return target.load();
}

void PID::setP(double input) {
    kP = input;
}

void PID::setI(double input) {
    kI = input;
}

void PID::setP(double input) {
    kD = input;
}



