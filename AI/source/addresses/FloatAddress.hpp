#ifndef FLOATADDRESS_HPP
#define FLOATADDRESS_HPP

#include "Address.hpp"

class FloatAddress : public Address{
public:

    FloatAddress(std::string n, std::string a): Address(n,a){}

    int ParseBytes(char);
};

#endif