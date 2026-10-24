#include "../../Renderer/Shader.h"

namespace Wongo::OpenGL
{

    class Shader : public Wongo::Shader
    {
        friend class Program;
    public:
        Shader(Description desc);
        ~Shader() override;
    
    private:
        unsigned int m_shader = 0;
    };

}
