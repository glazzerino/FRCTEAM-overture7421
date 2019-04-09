#pragma once
#include <string>
#include <iostream>

class Datapool {
    public:
        static Datapool* getInstance();
        void Print();
    private:
        Datapool(Datapool const&) = delete;
        void operator=(Datapool const&) = delete;
        static Datapool* instance;
};