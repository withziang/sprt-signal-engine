#include "internal/log.h"
#include <string>
#include <iostream>

namespace sse{
    Logger& Logger::instance(){
        static Logger logger;
        return logger;
    }

    void Logger::log(const std::string& msg){
        std::cout << "Log: " << msg;
    }

    void Logger::error(const std::string& msg){
        std::cout << "Error: " << msg;
    }
}