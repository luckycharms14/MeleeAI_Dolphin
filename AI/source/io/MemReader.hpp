#ifndef MEM_READER_HPP
#define MEM_READER_HPP

#include "GameState.hpp"

#include <string>
#include <functional>

namespace io {
    
class MemReader {   
public:
    //blocks execution and calls callback when data is received
    virtual void MonitorMemory(std::function<void(std::string,std::string)>);
};

}
#endif