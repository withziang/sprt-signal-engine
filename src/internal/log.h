#pragma once
#include <string>

namespace sse{
    class Logger{
    public:
        static Logger& instance();

        void log(const std::string& msg);
        void error(const std::string& msg);

        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
        Logger(Logger&&) = delete;
        Logger& operator=(Logger&&) = delete;
    private:
        Logger();
        ~Logger() = default;
    };
}