#ifndef STATE_HPP
#define STATE_HPP

#include <string>

namespace io{

class State{
public:

    void set(std::string,int);
    void set(std::string,bool);
    void set(std::string,float);

    int getInt(std::string);
    bool getBool(std::string);
    float getFloat(std::string);

private:
    std::map<std::string,float> _floatValues;
    std::map<std::string,int> _integerValues;
    std::map<std::string,bool> _booleanValues;
};

}
#endif