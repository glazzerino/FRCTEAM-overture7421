#include "PID/PID.h"

PID::PID(){
    thread PIDThread(&PID::controlLoop, this);
    PIDThread.detach();
    target.store(0.0);
    feedback.store(0.0);
    output.store(0.0);
}

void PID::controlLoop() {
    while (true) {
        double timeStep = chrono::duration<double>(chrono::high_resolution_clock::now() - lastUpdateTag).count();
         double currentError = target.load() - feedback.load();
        if (isContinous) {
            
            if (currentError > maxError) {
                currentError -= maxError * 2;
            } if(currentError < -maxError) {
                currentError += maxError * 2;
            }
        } 
        double eDelta =  (currentError - lastError);

        if (isContinous) {

            if (eDelta > maxError) {
                eDelta -= maxError * 2;
            } 
            if (eDelta < -maxError) {
                eDelta += maxError * 2;
            }
        }
        eDelta = eDelta / timeStep;
        integral += currentError * timeStep;
        double currentOutput = (currentError * kP) + (integral * kI) + (eDelta * kD);
        output.store(currentOutput);

        lastError = currentError;
        lastUpdateTag = chrono::high_resolution_clock::now();
        atomicCurrentError.store(currentError);
        this_thread::sleep_for(chrono::milliseconds(20));
    }
}

void PID::setTarget(double input) {
    target.store(input);
}

void PID::setFeedback(double feedback) {
    this -> feedback.store(feedback);
}

double PID::getOutput() {
    return output.load();
}

void PID::setP(double input) {
    kP = input;
}

void PID::setI(double input) {
    kI = input;
}

void PID::setD(double input) {
    kD = input;
}

void PID::setContinous(bool input) {
    isContinous = input;
}

void PID::setUpperLimit(double input) {
     upperLimit = input;
     maxError = (upperLimit - lowerLimit) / 2;
}

void PID::setLowerLimit(double input) {
    lowerLimit = input;
    maxError = (upperLimit - lowerLimit) / 2;
}

double PID::getCurrentError() {
    return atomicCurrentError.load();
}

