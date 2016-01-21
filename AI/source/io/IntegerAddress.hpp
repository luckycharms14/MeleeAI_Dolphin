#ifndef INTEGERADDRESS_HPP
#define INTEGERADDRESS_HPP

#include "Address.hpp"
#include <string>

namespace io {

class IntegerAddress : public Address{
public:

    IntegerAddress(std::string n, std::string a, int s = 0, int m = 0xFFFFFFFF): Address(n,a), shift(s), mask(m) {}

    int ParseBytes(long);
    int shift;
    int mask;
};

}
#endif