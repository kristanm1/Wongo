#ifndef _IMGUI_LAYER_
#define _IMGUI_LAYER_

struct ImGuiContext;

namespace Wongo
{

    class ImGuiLayer
    {
    public:
        ImGuiLayer(void* nativeWindow);
        ~ImGuiLayer();

        void Begin();
        void End();
    private:
        const char* m_glslVersion = nullptr;
    };

}

#endif
