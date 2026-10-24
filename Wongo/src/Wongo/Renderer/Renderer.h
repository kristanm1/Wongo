#ifndef _RENDERER_
#define _RENDERER_

#include "Backend.h"
#include "Core.h"

namespace Wongo
{

    class Renderer : private RenderObjectBase
    {
    public:
        static void CreateBackend(Backend::Type type);
        static Backend::Type GetBackendType();

        static void SetViewport(int x, int y, int width, int height) { s_backend->SetViewport(x, y, width, height); }
        static void SetColor(float r, float g, float b, float a) { s_backend->SetColor(r, g, b, a); }
        static void Clear(Backend::ClearMask mask) { s_backend->Clear(mask); }
        static void CullFace(Backend::CullFaces face) { s_backend->CullFace(face); }
        static void EnableDepthTest(bool enable) { s_backend->EnableDepthTest(enable); }
        static void DrawElements(Wongo::VertexArray const& vao) { s_backend->DrawElements(vao); }
    
    private:
        static Backend::Type s_type;
        static std::unique_ptr<Backend> s_backend;
    };

}

#endif
