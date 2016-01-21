#ifndef BOOLADDRESS_HPP
#define BOOLADDRESS_HPP

#include "Address.hpp"
#include <string>

namespace io {

class BoolAddress : public Address{
public:

    BoolAddress(std::string n, std::string a, int cv, int s = 0, int m = 0xFFFFFFFF): Address(n,a), compareValue(cv), shift(s), mask(m) {}

    bool ParseBytes(long);
    int compareValue;
    int shift;
    int mask;
};

}
#endif