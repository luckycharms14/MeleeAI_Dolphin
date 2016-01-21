#ifndef STATE_HPP
#define STATE_HPP

#include <string>

namespace io{

class State{
public:

    void setInt(std::string,int);
    void setBool(std::string,bool);
    void setFloat(std::string,float);

    void getInt(std::string);
    void getBool(std::string);
    void getFloat(std::string);

    std::map<std::string,float> floatValues;
    std::map<std::string,int> integerValues;
    std::map<std::string,bool> booleanValues;
};

}
#endif