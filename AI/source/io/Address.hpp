#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include <string>

namespace io{

class Address{
public:

    Address(std::string n, std::string a): name(n), address(a) {}

    std::string name;
    std::string address;
};

}
#endif