#include "Core.h"
#include "../../Renderer/Buffer.h"
#include "../../Renderer/Shader.h"
#include "../../Logger.h"

namespace
{
    static char const *s_sourceApi = "API";
    static char const *s_sourceWindowSystem = "Window System";
    static char const *s_sourceShaderCompiler = "Shader Compiler";
    static char const *s_sourceThirdParty = "Third Party";
    static char const *s_sourceApplication = "Application";

    static char const* s_typeError = "Error";
    static char const* s_typeDeprecatedBehviour = "Deprecated Behaviour";
    static char const* s_typeUndefinedBehaviour = "Undefined Behaviour";
    static char const* s_typePortability = "Portability";
    static char const* s_typePerformance = "Performance";
    static char const* s_typeMarker = "Marker";
    static char const* s_typePushGroup = "Push Group";
    static char const* s_typePopGroup = "Pop Group";

    static char const *s_other = "Other";
    static char const *s_unknown = "Unknown";

    char const* GetSourceDescription(unsigned int source)
    {
        switch (source)
        {
            case GL_DEBUG_SOURCE_API:             return s_sourceApi;
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   return s_sourceWindowSystem;
            case GL_DEBUG_SOURCE_SHADER_COMPILER: return s_sourceShaderCompiler;
            case GL_DEBUG_SOURCE_THIRD_PARTY:     return s_sourceThirdParty;
            case GL_DEBUG_SOURCE_APPLICATION:     return s_sourceApplication;
            case GL_DEBUG_SOURCE_OTHER:           return s_other;
            default:                              return s_unknown;
        }
    }

    char const* GetTypeDescription(unsigned int type)
    {
        switch (type)
        {
            case GL_DEBUG_TYPE_ERROR:               return s_typeError;
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return s_typeDeprecatedBehviour;
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  return s_typeUndefinedBehaviour;
            case GL_DEBUG_TYPE_PORTABILITY:         return s_typePortability;
            case GL_DEBUG_TYPE_PERFORMANCE:         return s_typePerformance;
            case GL_DEBUG_TYPE_MARKER:              return s_typeMarker;
            case GL_DEBUG_TYPE_PUSH_GROUP:          return s_typePushGroup;
            case GL_DEBUG_TYPE_POP_GROUP:           return s_typePopGroup;
            case GL_DEBUG_TYPE_OTHER:               return s_other;
            default:                                return s_unknown;
        }
    }
}

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
    char const* message,
    void const* userParam)
{
    // ignore non-significant error/warning codes
    if(id == 131169 || id == 131185 || id == 131218 || id == 131204)
    {
        return;
    }

    char const format[] = "OpenGL debug callback, source: %s type: %s message: %s\n";
    switch (severity)
    {
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            LOG_INFO_CORE(format, GetSourceDescription(source), GetTypeDescription(type), message);
            break;
        case GL_DEBUG_SEVERITY_LOW:
        case GL_DEBUG_SEVERITY_MEDIUM:
            LOG_WARN_CORE(format, GetSourceDescription(source), GetTypeDescription(type), message);
            break;
        default:
            LOG_ERROR_CORE(format, GetSourceDescription(source), GetTypeDescription(type), message);
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
