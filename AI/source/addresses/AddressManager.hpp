#ifndef ADDRESSMANAGER_HPP
#define ADDRESSMANAGER_HPP

#include <map>
#include <string>
#include <vector>
#include <MemoryValue.hpp>

class AddressManager {
public:
    AddressManager(){}

    void add(IntegerValue memValue);
    void add(FloatValue memValue);
    void add(BooleanValue memValue);

    std::map<std::string,std::vector<IntegerValue>> integerMap;
    std::map<std::string,std::vector<FloatValue>> floatMap;
    std::map<std::string,std::vector<BooleanValue>> booleanMap;
};

#endif