#include "Core.h"
#include "../../Renderer/Buffer.h"
#include "../../Renderer/Shader.h"
#include "../../Logger.h"

void Wongo::OpenGL::ClearErrors()
{
    while (glGetError() != GL_NO_ERROR);
}

bool Wongo::OpenGL::LogErrors(const char* function, const char* file, int line)
{
    bool error = false;
    unsigned int errorType;
    while ((errorType = glGetError()) != GL_NO_ERROR)
    {
        LOG_ERROR_CORE("OpenGL error: %u call to %s at file %s line %d", errorType, function, file, line);
    }
    return error;
}

void Wongo::OpenGL::ErrorCallback(
    unsigned int source,
    unsigned int type,
    unsigned int id,
    unsigned int severity,
    int length,
    const char *message,
    const void *userParam)
{
    static char const format[] = "OpenGL debug callback: %s\n";
    switch (severity)
    {
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            LOG_INFO_CORE(format, message);
            break;
        case GL_DEBUG_SEVERITY_LOW:
        case GL_DEBUG_SEVERITY_MEDIUM:
            LOG_WARN_CORE(format, message);
            break;
        default:
            LOG_ERROR_CORE(format, message);
            break;
    }

    ASSERT(false);
}

GLenum Wongo::OpenGL::GetDataType(Wongo::DataType type)
{
    switch (type)
    {
        case Wongo::DataType::UnsignedInt:
            return GL_UNSIGNED_INT;
        case Wongo::DataType::Float:
            return GL_FLOAT;
        default:
            ASSERT(false);
            return 0;
    }
}

GLenum Wongo::OpenGL::GetShaderType(Wongo::Shader::Type type)
{
    switch (type)
    {
        case Wongo::Shader::Type::Vertex:
            return GL_VERTEX_SHADER;
        case Wongo::Shader::Type::Fragment:
            return GL_FRAGMENT_SHADER;
        default:
            ASSERT(false);
            return 0;
    }
}

GLenum Wongo::OpenGL::GetBoolType(bool b)
{
    return b ? GL_TRUE : GL_FALSE;
}

GLenum Wongo::OpenGL::GetCullFaceType(Wongo::Backend::CullFaces type)
{
    switch (type)
    {
        case Wongo::Backend::CullFaces::Front:
            return GL_FRONT;
        case Wongo::Backend::CullFaces::Back:
            return GL_FRONT;
        default:
            return GL_FRONT_AND_BACK;
    }
}

unsigned int Wongo::OpenGL::GetDataTypeSize(GLenum glType)
{
    switch (glType)
    {
        case GL_UNSIGNED_INT:
        case GL_FLOAT:
            return 4;
        default:
            ASSERT(false);
            return 0;
    }
}
