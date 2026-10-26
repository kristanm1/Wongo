#pragma once

#include "../../Renderer/Program.h"
#include "glm/glm.hpp"

#include <string>
#include <unordered_map>

namespace Wongo::OpenGL
{

    class Program : public Wongo::Program
    {
    public:
        Program();
        ~Program() override;

        void AttachShader(Wongo::Shader *shader) override;
        bool Link() override;
        void Use() const override;
        void Unuse() const override;

        void SetInt(std::string const& name, int value) const override;
        void SetFloat(std::string const& name, float value) const override;
        void SetFloatMat4(std::string const& name, glm::mat4 const& value) const override;

    private:
        unsigned int FindUniform(std::string const& name) const;

    private:
        unsigned int m_program = 0;
        mutable std::unordered_map<std::string, unsigned int> m_uniforms{};
    };

}
