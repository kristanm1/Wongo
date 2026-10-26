#pragma once

#include "Core.h"

#include <memory>
#include <string>

namespace Wongo
{

    class Shader : private Wongo::RenderObjectBase
    {
    public:

        enum class Type
        {
            None,
            Vertex,
            Fragment,
        };

        struct Description
        {
            enum class ContentType // .content string contains
            {
                None,
                Path,   // path to source file
                Source, // source
            };

            Type shaderType = Type::None;
            ContentType contentType = ContentType::None;
            std::string content{};
        };

        static std::unique_ptr<Shader> Create(Description);
    };

}