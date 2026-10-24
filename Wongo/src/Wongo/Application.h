#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Renderer/Renderer.h"
#include "Layer.h"
#include "ImGuiLayer.h"

#include <vector>
#include <memory>

namespace Wongo
{

    class Window;
    struct ImGuiContext;

    class Application
    {
    public:
        Application();
        virtual ~Application() = default;

        template<typename T, typename... Args>
        void PushLayer(Args&&... args)
        {
            auto layer = std::make_unique<T>(std::forward<Args>(args)...);
            layer->OnCreate(*this);
            m_layers.push_back(std::move(layer));
        }

        Window& GetWindow() { return *m_window; }

        void Run();

    protected:
        bool m_running = true;
        std::unique_ptr<Wongo::Window> m_window;
        std::unique_ptr<Wongo::ImGuiLayer> m_imGuiLayer;
        std::vector<std::unique_ptr<Wongo::Layer>> m_layers{};

    private:
        void OnEvent(Wongo::Event const& event);
    };

    // To be defined in Client
    Application* CreateApplication();

}