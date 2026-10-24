#pragma once

#ifdef WONGO_PLATFORM_WINDOWS

#include "Application.h"
#include <memory>

int main(int argc, char* argv[])
{
    std::unique_ptr<Wongo::Application>(Wongo::CreateApplication())->Run();
    return 0;
}

#endif
