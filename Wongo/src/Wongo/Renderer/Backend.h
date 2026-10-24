#ifndef _RENDER_BACKEND_
#define _RENDER_BACKEND_

#include "Core.h"
#include "VertexArray.h"
#include "../Core.h"

#include <memory>

namespace Wongo
{

    class Backend : RenderObjectBase
    {
        friend class Renderer;
    public:
        enum class Type
        {
            None = -1,
            OpenGL = 0,
            Count, // idea: support multy backends and store each in array of size Count
        };

        enum class ClearMask : unsigned int
        {
            None = 0,
            Color = BIT(1),
            Depth = BIT(2),
        };

        enum class CullFaces
        {
            Front,
            Back,
            FrontAndBack,
        };
    
    protected:

        virtual void SetViewport(int x, int y, int width, int height) = 0;
        virtual void SetColor(float r, float g, float b, float a) = 0;
        virtual void Clear(ClearMask mask) = 0;
        virtual void CullFace(Backend::CullFaces face) = 0;
        virtual void EnableDepthTest(bool enable) = 0;
        virtual void DrawElements(Wongo::VertexArray const& vao) = 0;
    };

    constexpr Wongo::Backend::ClearMask operator|(Wongo::Backend::ClearMask lhs, Wongo::Backend::ClearMask rhs)
    {
        return static_cast<Wongo::Backend::ClearMask>(static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs));
    }

}

#endif
