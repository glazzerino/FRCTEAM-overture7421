#pragma once
#include <map>
#include <iostream>
#include <string>

struct DataPoolElement {
    int number;
    double decimal;
    std::string string;
};

/**
 * This class serves as flexible database to store a subsystem's
 * information, with the final purpose of sharing data between
 * subsystems*/
/*class DataPool final {
    private:
        DataPool() {
            std::cout << "DataPool started" << "\n";
        }
        std::map<std::string ,std::map<DataPoolElement>>  groupMap;
    public:
        static DataPool &getInstance() {
            static DataPool singleton;
            return singleton;
        } 
        DataPoolElement getData(const std::string &group, const std::string &key) {
            return groupMap[group][key];
        }
};*/