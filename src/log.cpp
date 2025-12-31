#include "internal/log.h"

#include <iostream>

namespace sse{
    Logger& Logger::instance(){
        static Logger logger;
        return logger;
    }

    void Logger::log(const std::string& msg){
        std::cout << "Log: " << msg << "\n";
    }

    void Logger::error(const std::string& msg){
        std::cout << "Error: " << msg << "\n";
    }
}