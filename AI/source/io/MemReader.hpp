#ifndef MEM_READER_HPP
#define MEM_READER_HPP

#include "GameState.hpp"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <poll.h>

class MemReader {   
public:
    
    virtual void MonitorMemory(std::function<void(std::string,std::string));
};

#endif