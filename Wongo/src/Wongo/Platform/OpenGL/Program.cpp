#include "Program.h"
#include "Shader.h"
#include "Core.h"
#include "../../Core.h"
#include "../../Logger.h"
#include "glm/gtc/type_ptr.hpp"

#include <iostream>
#include <unordered_map>
#include <glad/gl.h>

Wongo::OpenGL::Program::Program()
{
    GLCallRet(m_program, glCreateProgram());
}

Wongo::OpenGL::Program::~Program()
{
    GLCall(glDeleteProgram(m_program));
}

void Wongo::OpenGL::Program::AttachShader(std::shared_ptr<Wongo::Shader> const& shader)
{
    GLCall(glAttachShader(m_program, static_cast<Shader*>(shader.get())->m_shader));
}

bool Wongo::OpenGL::Program::Link()
{
    GLCall(glLinkProgram(m_program));

    GLint success = GL_FALSE;
    glGetProgramiv(m_program, GL_LINK_STATUS, &success);

    if (!success)
    {
        GLint length = 0;
        glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &length);

        std::string log(length, '\0');
        glGetProgramInfoLog(m_program, length, nullptr, &log[0]);
        LOG_WARN_CORE("Linking program failed: %s", log);
    }

    return !!success;
}

void Wongo::OpenGL::Program::Use() const
{
    GLCall(glUseProgram(m_program));
}

void Wongo::OpenGL::Program::Unuse() const
{
    GLCall(glUseProgram(0));
}

unsigned int Wongo::OpenGL::Program::FindUniform(std::string const& name) const
{
    unsigned int uniform;
    if (m_uniforms.find(name) == m_uniforms.end())
    {
        GLCallRet(uniform, glGetUniformLocation(m_program, name.c_str()));
        m_uniforms[name] = uniform;
    }
    else
    {
        uniform = m_uniforms[name];
    }

    return uniform;
}

void Wongo::OpenGL::Program::SetInt(std::string const& name, int value) const
{
    unsigned int uniform = FindUniform(name);
    GLCall(glUniform1i(uniform, value));
}

void Wongo::OpenGL::Program::SetFloat(std::string const& name, float value) const
{
    unsigned int uniform = FindUniform(name);
    GLCall(glUniform1f(uniform, value));
}

void Wongo::OpenGL::Program::SetFloatMat4(std::string const& name, glm::mat4 const& value) const
{
    unsigned int uniform = FindUniform(name);
    GLCall(glUniformMatrix4fv(uniform, 1, GL_FALSE, glm::value_ptr(value)));
}
