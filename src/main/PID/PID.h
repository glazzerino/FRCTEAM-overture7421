#pragma oncew
#include <atomic>
#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std;
class PID {
    public:

        PID();
        double getOutput();
        void setTarget(double input);
        void setFeedback(double feedback);
        void setP(double proportional);
        void setI(double integrate);
        void setD(double differential);
        void setContinous(bool input);
        void setUpperLimit(double input);
        void setLowerLimit(double input);
        double getCurrentError();
    private:
        void controlLoop();
        atomic<double> output;
        atomic<double> feedback;
        atomic <double> target;
        atomic<double> atomicCurrentError;
        double kP = 0.0;
        double kI = 0.0;
        double kD = 0.0;
        double integral = 0.0;
        double lastError = 0.0;
        void setLoopName(string &loopName);
        chrono::high_resolution_clock::time_point lastUpdateTag;
        double lowerLimit = 0.0;
        double upperLimit = 0.0;
        bool isContinous = false;
        double maxError;
};