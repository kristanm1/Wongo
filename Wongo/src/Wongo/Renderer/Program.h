#ifndef _PROGRAM_
#define _PROGRAM_

#include "Shader.h"
#include "glm/fwd.hpp"

#include <memory>
#include <string>

namespace Wongo
{

    class Program : private Wongo::RenderObjectBase
    {
    public:
        static std::unique_ptr<Program> Create();

        virtual void AttachShader(Shader* shader) = 0;
        virtual bool Link() = 0;
        virtual void Use() const = 0;
        virtual void Unuse() const = 0;

        virtual void SetInt(std::string const& name, int value) const = 0;
        virtual void SetFloat(std::string const& name, float value) const = 0;
        virtual void SetFloatMat4(std::string const& name, glm::mat4 const& value) const = 0;
    };

}

#endif
