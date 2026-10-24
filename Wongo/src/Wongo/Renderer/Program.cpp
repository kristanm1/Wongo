#include "Program.h"
#include "Backend.h"
#include "Renderer.h"
#include "../Platform/OpenGL/Program.h"

std::shared_ptr<Wongo::Program> Wongo::Program::Create()
{
    switch (Wongo::Renderer::GetBackendType())
    {
        case Wongo::Backend::Type::OpenGL: return std::make_shared<Wongo::OpenGL::Program>();
        default: return nullptr;
    }
}
