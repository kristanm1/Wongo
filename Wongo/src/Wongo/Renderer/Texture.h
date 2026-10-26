#pragma once

#include "Core.h"

#include <memory>
#include <string>

namespace Wongo
{

    class Texture : private Wongo::RenderObjectBase
    {
    public:

        struct Description
        {
            std::string path;
        };

        static std::unique_ptr<Texture> Create(Description);

        virtual void Bind(unsigned int unit) = 0;
    };

}
