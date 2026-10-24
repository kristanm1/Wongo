#include "Texture.h"
#include "Core.h"
#include "../../Utils/Image.h"

Wongo::OpenGL::Texture::Texture(Description desc)
{
    Wongo::Image image({ desc.path, true });

    GLCall(glCreateTextures(GL_TEXTURE_2D, 1, &m_texture));

    GLCall(glTextureParameteri(m_texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTextureParameteri(m_texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCall(glTextureParameteri(m_texture, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GLCall(glTextureParameteri(m_texture, GL_TEXTURE_WRAP_T, GL_REPEAT));

    GLCall(glTextureStorage2D(m_texture, 1, GL_RGBA8, image.GetWidth(), image.GetHeight()));
    GLCall(glTextureSubImage2D(m_texture, 0, 0, 0, image.GetWidth(), image.GetHeight(), GL_RGB, GL_UNSIGNED_BYTE, image.GetPixels()));
}

Wongo::OpenGL::Texture::~Texture()
{
    GLCall(glDeleteTextures(1, &m_texture));
}

void Wongo::OpenGL::Texture::Bind(unsigned int unit)
{
    GLCall(glBindTextureUnit(unit, m_texture));
}
