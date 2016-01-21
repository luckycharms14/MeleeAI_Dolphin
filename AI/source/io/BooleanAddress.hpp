#ifndef BOOLEANADDRESS_HPP
#define BOOLEANADDRESS_HPP

#include "Address.hpp"
#include <string>

namespace io {

class BooleanAddress : public Address{
public:

    BooleanAddress(std::string n, std::string a, int cv, int s = 0, int m = 0xFFFFFFFF): Address(n,a), compareValue(cv), shift(s), mask(m) {}

    bool ParseBytes(long);
    int compareValue;
    int shift;
    int mask;
};

}
#endif