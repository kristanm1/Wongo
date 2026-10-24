#ifndef _OPENGL_BACKEND_
#define _OPENGL_BACKEND_

#include "../../Renderer/Backend.h"
#include "../../Renderer/VertexArray.h"

namespace Wongo::OpenGL
{

    class Backend : public Wongo::Backend
    {
    public:
        Backend() = default;
        ~Backend() override = default;

        void SetViewport(int x, int y, int width, int height) override;
        void SetColor(float r, float g, float b, float a) override;
        void Clear(ClearMask mask) override;
        void CullFace(Backend::CullFaces face) override;
        void EnableDepthTest(bool enable) override;
        void DrawElements(Wongo::VertexArray const& vao) override;
    };

}

#endif
