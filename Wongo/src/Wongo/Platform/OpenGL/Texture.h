#pragma once

#include "../../Renderer/Texture.h"

namespace Wongo::OpenGL
{

    class Texture : public Wongo::Texture
    {
    public:
        Texture(Description desc);
        ~Texture();

        void Bind(unsigned int unit) override;
    private:
        unsigned int m_texture;
    };

}
