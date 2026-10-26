#include "Buffer.h"
#include "Backend.h"
#include "Renderer.h"
#include "../Logger.h"
#include "../Platform/OpenGL/Buffer.h"

std::unique_ptr<Wongo::VertexBuffer> Wongo::VertexBuffer::Create(Wongo::VertexBuffer::Description desc)
{
    switch (Wongo::Renderer::GetBackendType())
    {
        case Wongo::Backend::Type::OpenGL:
            return std::make_unique<Wongo::OpenGL::VertexBuffer>(desc);
        default:
            return nullptr;
    }
}

std::unique_ptr<Wongo::IndexBuffer> Wongo::IndexBuffer::Create(Wongo::IndexBuffer::Description desc)
{
    switch (Wongo::Renderer::GetBackendType())
    {
        case Wongo::Backend::Type::OpenGL:
            return std::make_unique<Wongo::OpenGL::IndexBuffer>(desc);
        default:
            return nullptr;
    }
}

std::unique_ptr<Wongo::UniformBuffer> Wongo::UniformBuffer::Create(Wongo::UniformBuffer::Description desc)
{
    switch (Wongo::Renderer::GetBackendType())
    {
        case Wongo::Backend::Type::OpenGL:
            return std::make_unique<Wongo::OpenGL::UniformBuffer>(desc);
        default:
            return nullptr;
    }
}
