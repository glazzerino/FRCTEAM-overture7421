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
        void SetI(double integrate);
        void setD(double differential);
    private:
        void controlLoop();
        atomic<double> output;
        atomic<double> feedback;
        atomic <double> target;
        double kP;
        double kI;
        double kD;
        double integral = 0.0;
        double lastError = 0.0;
        void setLoopName(string &loopName);
        chrono::high_resolution_clock::time_point lastUpdateTag;
};