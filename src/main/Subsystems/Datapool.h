#pragma once
#include <string>
#include <iostream>
#include <map>

/**
 * Singleton that allows to share info between subsystems, currently relies solely on a string double k v pair
 * */
class Datapool {
    public:
        static Datapool& getInstance();
        void Print();
        double getData(const std::string &groupName,const std::string &sysName);
        void addData(const std::string &groupName,const std::string &memberName,double value);
    private:
        Datapool();
        Datapool(Datapool const&) = delete;
        void operator=(Datapool const&) = delete;
        static Datapool& instance;
        std::map<std::string, std::map<std::string, double>> groups;
};