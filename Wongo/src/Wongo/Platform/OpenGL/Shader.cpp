#include "Shader.h"
#include "Core.h"
#include "../../Core.h"
#include "../../Logger.h"

#include <glad/gl.h>

Wongo::OpenGL::Shader::Shader(Description desc)
{
    std::string source;
    switch (desc.contentType)
    {
        case Wongo::Shader::Description::ContentType::Path:
            source = Wongo::LoadText(desc.content);
            break;
        case Wongo::Shader::Description::ContentType::Source:
            source = desc.content;
        default:
            ASSERT(false);
            LOG_WARN_CORE("Shader Description Content type is None!");
    }

    GLCallRet(m_shader, glCreateShader(GetShaderType(desc.shaderType)));

    const char* pSource = source.c_str();
    GLCall(glShaderSource(m_shader, 1, &pSource, nullptr));
    GLCall(glCompileShader(m_shader));
}

Wongo::OpenGL::Shader::~Shader()
{
    GLCall(glDeleteShader(m_shader));
}
