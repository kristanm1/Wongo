#include "Application.h"
#include "Logger.h"
#include "Window.h"
#include "Events/WindowEvent.h"
#include "Renderer/Backend.h"
#include "Renderer/Buffer.h"
#include "Renderer/VertexArray.h"
#include "Renderer/Shader.h"
#include "Renderer/Program.h"
#include "Renderer/Texture.h"

#include "imgui.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <memory>

Wongo::Application::Application()
    : m_window(Wongo::Window::Create(Wongo::WindowProperties{}, [this](Event const& event){OnEvent(event);}))
    , m_imGuiLayer(std::make_unique<ImGuiLayer>(m_window->GetNativeWindow()))
{
    Wongo::Renderer::CreateBackend(Wongo::Backend::Type::OpenGL);
}

void Wongo::Application::Run()
{
    while (m_running)
    {
        for (auto& layer : m_layers)
        {
            layer->OnUpdate();
        }

        m_imGuiLayer->Begin();
        for (auto& layer : m_layers)
        {
            layer->RenderImGui();
        }
        m_imGuiLayer->End();

        m_window->Update();
    }
}

void Wongo::Application::OnEvent(Wongo::Event const& event)
{
    //LOG_INFO_CORE("OnEvent %s", event.ToString().c_str());

    if (event.GetType() == Wongo::EventType::WindowClose)
    {
        m_running = false;
        event.Handle();
    }

    if (event.GetType() == Wongo::EventType::WindowResize)
    {
        auto const& resizeEvent = reinterpret_cast<WindowResizeEvent const&>(event);
        Wongo::Renderer::SetViewport(0, 0, resizeEvent.GetWidth(), resizeEvent.GetHeight());
    }

    for (auto it = m_layers.rbegin(); it != m_layers.rend(); it++)
    {
        if (event.IsHandled())
        {
            break;
        }

        (*it)->OnEvent(event);
    }
}
