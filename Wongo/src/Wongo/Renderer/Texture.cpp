#include "Texture.h"
#include "Backend.h"
#include "Renderer.h"
#include "../Platform/OpenGL/Texture.h"

std::shared_ptr<Wongo::Texture> Wongo::Texture::Create(Description desc)
{
    switch (Renderer::GetBackendType()) {
        case Wongo::Backend::Type::OpenGL: return std::make_shared<Wongo::OpenGL::Texture>(desc);
        default: return nullptr;
    }
}
