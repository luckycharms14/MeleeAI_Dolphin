#ifndef FLOATADDRESS_HPP
#define FLOATADDRESS_HPP

#include "Address.hpp"
#include <string>

class FloatAddress : public Address{
public:

    FloatAddress(std::string n, std::string a): Address(n,a){}

    float ParseBytes(long);
};

#endif