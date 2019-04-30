#include "Subsystems/Datapool.h"

Datapool::Datapool(){}

 Datapool& Datapool::getInstance() {
    static Datapool instance;
    return instance;
}
/**
 * Requires a groupname to avoid overwritting another map
 * */

void Datapool::addData(const std::string &groupName,const std::string &memberName, double value) {
    std::map<std::string, double> member;
    member[memberName] = value;
    groups[groupName] = member;
}
/**
 * Accessing data requires a groupname entry, returns saved double value
 * */
double Datapool::getData(const std::string &groupName, const std::string &memberName) {
    return groups[groupName][memberName];
}
void Datapool::Print() {
    std::cout << "DATAPOOL STARTED\n";
}