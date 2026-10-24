#pragma once

#include <string>
#include <vector>
#include <cassert>

#ifndef WONGO_PLATFORM_WINDOWS
    #error Wongo supports Windows only
#endif

#define ASSERT(x) if((x)) __debugbreak();

#define BIT(x) (1 << (x))

namespace Wongo
{

    std::string LoadText(std::string const& path);

    bool LoadObj(
        std::string const& assetPath,
        std::string const& objPath,
        std::vector<float>& vertexData,
        std::vector<unsigned int>& indices,
        std::string& texturePath
    );

}
