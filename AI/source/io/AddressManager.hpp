#ifndef ADDRESSMANAGER_HPP
#define ADDRESSMANAGER_HPP

#include <map>
#include <string>
#include <vector>
#include "IntegerAddress.hpp"
#include "FloatAddress.hpp"
#include "BooleanAddress.hpp"

class AddressManager {
public:
    AddressManager(){}

    void add(IntegerAddress);
    void add(FloatAddress);
    void add(BooleanAddress);

    std::map<std::string,std::vector<IntegerAddress>> integerMap;
    std::map<std::string,std::vector<FloatAddress>> floatMap;
    std::map<std::string,std::vector<BooleanAddress>> booleanMap;
};

#endif