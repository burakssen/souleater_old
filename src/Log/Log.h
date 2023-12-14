#pragma once

#include <iostream>

#include <raylib.h>
#include <rres-raylib.h>

class Log
{
public:
    static void info(std::string message);
    static void warn(std::string message);
    static void error(std::string message);
    static void fatal(std::string message);

    static void stopRaylibLogging();

    ~Log() = default;

    Log &getInstance()
    {
        static Log instance;
        return instance;
    }

private:
    Log() = default;
};
