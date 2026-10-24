#include "VertexArray.h"
#include "Backend.h"
#include "Renderer.h"
#include "../Platform/OpenGL/VertexArray.h"

namespace Wongo
{

    std::shared_ptr<VertexArray> Wongo::VertexArray::Create()
    {
        switch (Wongo::Renderer::GetBackendType())
    {
        case Wongo::Backend::Type::OpenGL:
            return std::make_shared<Wongo::OpenGL::VertexArray>();
        default:
            return nullptr;
    }
    }

}
