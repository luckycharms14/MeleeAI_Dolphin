#ifndef INTADDRESS_HPP
#define INTADDRESS_HPP

#include "Address.hpp"
#include <string>

namespace io {

class IntAddress : public Address{
public:

    IntAddress(std::string n, std::string a, int s = 0, int m = 0xFFFFFFFF): Address(n,a), shift(s), mask(m) {}

    int ParseBytes(std::string);
    int shift;
    int mask;
};

}
#endif