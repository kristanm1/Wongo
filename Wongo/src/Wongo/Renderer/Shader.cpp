#include "Shader.h"
#include "Backend.h"
#include "Renderer.h"
#include "../Platform/OpenGL/Shader.h"

std::shared_ptr<Wongo::Shader> Wongo::Shader::Create(Description desc)
{
    switch (Wongo::Renderer::GetBackendType())
    {
        case Wongo::Backend::Type::OpenGL: return std::make_shared<Wongo::OpenGL::Shader>(desc);
        default: return nullptr;
    }
}
