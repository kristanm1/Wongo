#pragma once

#include "Core.h"

#define LOG_DEBUG_CORE(...) Wongo::Logger::DebugCore(__VA_ARGS__)
#define LOG_INFO_CORE(...) Wongo::Logger::InfoCore(__VA_ARGS__)
#define LOG_WARN_CORE(...) Wongo::Logger::WarnCore(__VA_ARGS__)
#define LOG_ERROR_CORE(...) Wongo::Logger::ErrorCore(__VA_ARGS__)

#define LOG_DEBUG_CLIENT(...) Wongo::Logger::DebugClient(__VA_ARGS__)
#define LOG_INFO_CLIENT(...) Wongo::Logger::InfoClient(__VA_ARGS__)
#define LOG_WARN_CLIENT(...) Wongo::Logger::WarnClient(__VA_ARGS__)
#define LOG_ERROR_CLIENT(...) Wongo::Logger::ErrorClient(__VA_ARGS__)

namespace Wongo
{

    class Logger
    {
    public:
        Logger() = delete;
        Logger const & operator=(Logger const&) = delete;

        static void DebugCore(const char* format, ...);
        static void InfoCore(const char* format, ...);
        static void WarnCore(const char* format, ...);
        static void ErrorCore(const char* format, ...);

        static void DebugClient(const char* format, ...);
        static void InfoClient(const char* format, ...);
        static void WarnClient(const char* format, ...);
        static void ErrorClient(const char* format, ...);
    };

}
