#ifndef GAMEEVENTDISPATCHER_HPP
#define GAMEEVENTDISPATCHER_HPP

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <memory>
#include "AddressManager.hpp"

namespace io{

class GameEventDispatcher {
public:
    GameEventDispatcher(std::unique_ptr<AddressManager> am);

    void AddListener(std::function<void(State)>);
    void AddListener(std::string,std::function<void(State)>);

    void AddFloatListener(std::string,std::function<void(float)>);
    void AddFloatListener(std::string,std::function<void(float,State)>);
    void AddBoolListener(std::string,std::function<void(bool)>);
    void AddBoolListener(std::string,std::function<void(bool,State)>);
    void AddIntListener(std::string,std::function<void(int)>);
    void AddIntListener(std::string,std::function<void(int,State)>);
    
    //pass this into memreader
    void ProcessMemory(std::string,std::string);

private:
    std::unique_ptr<State> _gameState;
    std::unique_ptr<AddressManager> _addressManager;
    std::vector<std::function<void(State)> _callbacks;
    std::map<std::string,std::function<void(State)> _stateCallbacks;
    std::map<std::string,std::function<void(float,State)> _floatCallbacks;
    std::map<std::string,std::function<void(int,State)> _intCallbacks;
    std::map<std::string,std::function<void(bool,State)> _boolCallbacks;
};

}
#endif