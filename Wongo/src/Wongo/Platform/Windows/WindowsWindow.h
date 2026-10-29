#pragma once

#include "../../Core.h"
#include "../../Window.h"

#include <memory>

struct GLFWwindow;

namespace Wongo
{

    namespace OpenGL
    {
        void ErrorCallback(
            unsigned int source,
            unsigned int type,
            unsigned int id,
            unsigned int severity,
            int length,
            const char *message,
            const void *userParam);
    }

    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(WindowProperties const& properties, EventSystem& eventSystem);
        
        ~WindowsWindow() override;
        void Update() override;

        unsigned int GetWidth() const override { return m_data.m_width; }
        unsigned int GetHeight() const override { return m_data.m_height; }
        void* GetNativeWindow() const override { return m_window; };

    public:
    private:

        struct WindowData
        {
            WindowData(std::string title, unsigned int width, unsigned int height, EventSystem& eventSystem)
                : m_title(title)
                , m_width(width)
                , m_height(height)
                , m_eventSystem(eventSystem)
            {}

            std::string m_title;
            unsigned int m_width;
            unsigned int m_height;
            EventSystem& m_eventSystem;
        };

        GLFWwindow* m_window;
        WindowData m_data;

        static void ErrorCallback(int errorNumber, const char *description);
        static void WindowCloseCallback(GLFWwindow *window);
        static void WindowResizeCallback(GLFWwindow *window, int width, int height);
        static void WindowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void WindowMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        static void WindowMousePositionCallback(GLFWwindow* window, double xpos, double ypos);
        static void WindowScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

    };

}