#include "Subsystems/Datapool.h"

Datapool::Datapool(){}

 Datapool& Datapool::getInstance() {
    static Datapool instance;
    return instance;
}
void Datapool::addData(const std::string &groupName,const std::string &memberName, double &value) {
    std::map<std::string, double> member;
    member[memberName] = value;
    groups[groupName] = member;
}

double Datapool::getData(const std::string &groupName, const std::string &memberName) {
    return groups[groupName][memberName];
}
void Datapool::Print() {
    std::cout << "DATAPOOL STARTED\n";
}