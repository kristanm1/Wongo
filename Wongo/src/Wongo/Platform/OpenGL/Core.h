#pragma once

#include "../../Core.h"
#include "../../Renderer/Core.h"
#include "../../Renderer/Shader.h"
#include "../../Renderer/Backend.h"

#include <glad/gl.h>

#define GLCall(func) do{\
    Wongo::OpenGL::ClearErrors(); \
    func; \
    ASSERT(Wongo::OpenGL::LogErrors(#func, __FILE__, __LINE__))} while(false)

#define GLCallRet(vardef, func) \
    Wongo::OpenGL::ClearErrors(); \
    vardef = func; \
    ASSERT(Wongo::OpenGL::LogErrors(#func, __FILE__, __LINE__))

namespace Wongo
{

    // todo: this should be moved into opengl backend!
    namespace OpenGL
    {
        void ClearErrors();
        bool LogErrors(const char* function, const char* file, int line);

        void ErrorCallback(
            unsigned int source,
            unsigned int type,
            unsigned int id,
            unsigned int severity,
            int length,
            const char *message,
            const void *userParam);

        GLenum GetDataType(Wongo::DataType type);
        GLenum GetShaderType(Wongo::Shader::Type type);
        GLenum GetBoolType(bool b);
        GLenum GetCullFaceType(Wongo::Backend::CullFaces type);
        unsigned int GetDataTypeSize(GLenum glType);

    }

}
