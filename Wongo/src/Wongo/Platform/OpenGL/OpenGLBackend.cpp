#include "OpenGLBackend.h"
#include "Core.h"
#include "VertexArray.h"

void Wongo::OpenGL::Backend::SetViewport(int x, int y, int width, int height)
{
    GLCall(glViewport(x, y, width, height));
}

void Wongo::OpenGL::Backend::SetColor(float r, float g, float b, float a)
{
    GLCall(glClearColor(r, g, b, a));
}

void Wongo::OpenGL::Backend::Clear(ClearMask mask)
{
    // todo: use mask!
    GLbitfield flags = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
    GLCall(glClear(flags));
}

void Wongo::OpenGL::Backend::CullFace(Backend::CullFaces face)
{
    GLCall(glCullFace(GetCullFaceType(face)));
}

void Wongo::OpenGL::Backend::EnableDepthTest(bool enable)
{
    if (enable)
        GLCall(glEnable(GL_DEPTH_TEST));
    else
        GLCall(glDisable(GL_DEPTH_TEST));
}

void Wongo::OpenGL::Backend::DrawElements(Wongo::VertexArray const& vao)
{
    vao.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, vao.GetIndexCount(), vao.GetIndexType(), nullptr));
}
