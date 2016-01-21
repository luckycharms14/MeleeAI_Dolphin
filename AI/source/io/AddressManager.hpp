#ifndef ADDRESSMANAGER_HPP
#define ADDRESSMANAGER_HPP

#include <map>
#include <string>
#include <vector>
#include <memory>
#include "IntAddress.hpp"
#include "FloatAddress.hpp"
#include "BoolAddress.hpp"

namespace io{

enum AddressType {
    floatAddress,
    intAddress,
    boolAddress
}

class AddressParse {
//used to specify the correct address type
public:
    AddressParse(std::unique_ptr<FloatAddress> fa) floatAddress(fa), intAddress(nullptr), boolAddress(nullptr), addressType(AddressType.floatAddress){};
    AddressParse(std::unique_ptr<IntAddress> ia) floatAddress(nullptr), intAddress(ia), boolAddress(nullptr), addressType(AddressType.intAddress){};
    AddressParse(std::unique_ptr<BoolAddress> ba) floatAddress(nullptr), intAddress(nullptr), boolAddress(ba), addressType(AddressType.boolAddress){};
    std::unique_ptr<FloatAddress> floatAddress;
    std::unique_ptr<IntAddress> intAddress;
    std::unique_ptr<BoolAddress> boolAddress;
    AddressType addressType;
};

class AddressManager {
public:
    AddressManager(){}

    std::vector<AddressParse> getByAddress(std::string);
    std::vector<AddressParse> getByName(std::string);

    void add(IntAddress);
    void add(FloatAddress);
    void add(BoolAddress);

private:
    std::map<std::string,std::vector<IntAddress>> _integerMap;
    std::map<std::string,std::vector<FloatAddress>> _floatMap;
    std::map<std::string,std::vector<BoolAddress>> _booleanMap;
};

}
#endif