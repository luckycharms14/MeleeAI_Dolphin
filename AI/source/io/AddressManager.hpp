#ifndef ADDRESSMANAGER_HPP
#define ADDRESSMANAGER_HPP

#include <map>
#include <string>
#include <vector>
#include "IntegerAddress.hpp"
#include "FloatAddress.hpp"
#include "BooleanAddress.hpp"

namespace io{

enum AddressType {
    floatAddress,
    integerAddress,
    booleanAddress
}

struct AddressParse {
    FloatAddress floatAddress;
    IntegerAddress integerAddress;
    BooleanAddress booleanAddress;
    AddressType addressType;
};

class AddressManager {
public:
    AddressManager(){}

    std::vector<AddressParse> getByAddress(std::string);
    std::vector<AddressParse> getByName(std::string);

    void add(IntegerAddress);
    void add(FloatAddress);
    void add(BooleanAddress);

private:
    std::map<std::string,std::vector<IntegerAddress>> _integerMap;
    std::map<std::string,std::vector<FloatAddress>> _floatMap;
    std::map<std::string,std::vector<BooleanAddress>> _booleanMap;
};

}
#endif