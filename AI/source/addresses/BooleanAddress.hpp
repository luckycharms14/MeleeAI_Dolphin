#ifndef INTEGERADDRESS_HPP
#define INTEGERADDRESS_HPP

#include "Address.hpp"

class IntegerAddress : public Address{
public:

    IntegerAddress(std::string n, std::string a, int cv, int s = 0, int m = 0xFFFFFFFF): Address(n,a), compareValue(cv), shift(s), mask(m) {}

    bool ParseBytes(long);
    int compareValue;
    int shift;
    int mask;
};

#endif