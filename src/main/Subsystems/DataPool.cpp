#include "Subsystems/DataPool.h"

 Datapool* getInstance() {
    static Datapool* instance;
    return instance;
}

void Datapool::Print() {
    std::cout << "DATAPOOL STARTED\n";
}