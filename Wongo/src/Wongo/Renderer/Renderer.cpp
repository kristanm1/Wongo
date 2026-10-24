#include "Renderer.h"
#include "../Logger.h"
#include "../Platform/OpenGL/OpenGLBackend.h"

Wongo::Backend::Type Wongo::Renderer::s_type{};
std::unique_ptr<Wongo::Backend> Wongo::Renderer::s_backend{};

Wongo::Backend::Type Wongo::Renderer::GetBackendType()
{
    return s_type;
}

void Wongo::Renderer::CreateBackend(Wongo::Backend::Type type)
{
    Wongo::Renderer::s_type = type;
    switch (type)
    {
        case Wongo::Backend::Type::OpenGL:
            Wongo::Renderer::s_backend = std::make_unique<Wongo::OpenGL::Backend>();
            break;
        default:
            ASSERT(false);
            LOG_ERROR_CORE("Unknown render backend type: %u", type);
            break;
    }
}
