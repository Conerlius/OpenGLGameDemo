#pragma once
#include <iostream>
#include <string>

// #define NS_BEGIN namespace OpenGLGame {
// #define NS_END }
// #define NS_USE using namespace OpenGLGame
#define NS_BEGIN 
#define NS_END 
#define NS_USE 

NS_BEGIN
    enum LogLevel
    {
        Info,
        Warning,
        Error
    };
    class EngineLog
    {
    public:
        static void mLog(std::string tag, LogLevel level, std::string msg)
        {
            std::cout<<tag<<' '<<msg<< std::endl;
        }
    };
#define LOG(tag, level, msg) \
    EngineLog::mLog(tag, level, msg)
NS_END
