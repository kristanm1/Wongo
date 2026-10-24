#include "Logger.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <cstdio>
#include <vector>

namespace
{
    std::shared_ptr<spdlog::logger> s_coreLogger = spdlog::stderr_color_mt("Core");
    std::shared_ptr<spdlog::logger> s_clientLogger = spdlog::stderr_color_mt("Client");
}

#define FORMAT_BUFFER \
        va_list args; \
        va_start(args, format); \
        int size = vsnprintf(nullptr, 0, format, args); \
        std::vector<char> buffer(size + 1, '\0'); \
        vsnprintf(&buffer[0], size, format, args); \
        va_end(args); \

namespace Wongo
{

    void Logger::DebugCore(const char* format, ...)
    {
        FORMAT_BUFFER;
        s_coreLogger->debug("{}", &buffer[0]);
    }

    void Logger::InfoCore(const char* format, ...)
    {
        FORMAT_BUFFER;
        s_coreLogger->info("{}", &buffer[0]);
    }

    void Logger::WarnCore(const char* format, ...)
    {
        FORMAT_BUFFER;
        s_coreLogger->warn("{}", &buffer[0]);
    }

    void Logger::ErrorCore(const char* format, ...)
    {
        FORMAT_BUFFER;
        s_coreLogger->error("{}", &buffer[0]);
    }

    void Logger::DebugClient(const char* format, ...)
    {
        FORMAT_BUFFER;
        s_clientLogger->debug("{}", &buffer[0]);
    }

    void Logger::InfoClient(const char* format, ...)
    {
        FORMAT_BUFFER;
        s_clientLogger->info("{}", &buffer[0]);
    }

    void Logger::WarnClient(const char* format, ...)
    {
        FORMAT_BUFFER;
        s_clientLogger->warn("{}", &buffer[0]);
    }

    void Logger::ErrorClient(const char* format, ...)
    {
        FORMAT_BUFFER;
        s_clientLogger->error("{}", &buffer[0]);
    }

}
