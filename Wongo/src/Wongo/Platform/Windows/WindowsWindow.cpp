#include "WindowsWindow.h"
#include "../../Logger.h"
#include "../../Events/WindowEvent.h"
#include "../../Events/KeyboardEvent.h"
#include "../../Events/MouseEvent.h"
#include "../../Events/ScrollEvent.h"
#include "../../Systems/Event/EventSystem.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <cassert>


void Wongo::WindowsWindow::ErrorCallback(int errorNumber, const char *description)
{
    LOG_ERROR_CORE("GLFW callback error number %d: description: %s", errorNumber, description);
}

void Wongo::WindowsWindow::WindowCloseCallback(GLFWwindow *window)
{
    WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
    data->m_eventSystem.TriggerEvent(WindowCloseEvent());
}

void Wongo::WindowsWindow::WindowResizeCallback(GLFWwindow *window, int width, int height)
{
    WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
    data->m_width = static_cast<unsigned int>(width);
    data->m_height = static_cast<unsigned int>(height);
    data->m_eventSystem.TriggerEvent(WindowResizeEvent(width, height));
}

void Wongo::WindowsWindow::WindowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
    switch (action)
    {
        case GLFW_PRESS:
            data->m_eventSystem.TriggerEvent(KeyboardPressedEvent(scancode, 0));
            break;
        case GLFW_REPEAT:
            data->m_eventSystem.TriggerEvent(KeyboardPressedEvent(scancode, 1));
            break;
        case GLFW_RELEASE:
            data->m_eventSystem.TriggerEvent(KeyboardReleasedEvent(scancode));
            break;
    }
}

void Wongo::WindowsWindow::WindowMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
    switch (action)
    {
        case GLFW_PRESS:
            data->m_eventSystem.TriggerEvent(MouseButtonPressedEvent(button));
            break;
        case GLFW_RELEASE:
            data->m_eventSystem.TriggerEvent(MouseButtonReleasedEvent(button));
            break;
    }
}

void Wongo::WindowsWindow::WindowMousePositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
    data->m_eventSystem.TriggerEvent(MouseMoveEvent(xpos, ypos));
}

void Wongo::WindowsWindow::WindowScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
    data->m_eventSystem.TriggerEvent(ScrollMoveEvent(xoffset, yoffset));
}

Wongo::WindowsWindow::WindowsWindow(WindowProperties const& properties, EventSystem& eventSystem)
    : m_data(properties.m_title, properties.m_width, properties.m_height, eventSystem)
{
    int glfwInitStatus = glfwInit();
    assert(glfwInitStatus && "Could not initialize GLFW!");

    glfwSetErrorCallback(ErrorCallback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifndef NDEBUG
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif

    m_window = glfwCreateWindow(m_data.m_width, m_data.m_height, m_data.m_title.c_str(), NULL, NULL);
    ASSERT(!m_window);

    glfwMakeContextCurrent(m_window);

    glfwSetWindowUserPointer(m_window, &m_data);
    glfwSetWindowCloseCallback(m_window, WindowCloseCallback);
    glfwSetWindowSizeCallback(m_window, WindowResizeCallback);
    glfwSetKeyCallback(m_window, WindowKeyCallback);
    glfwSetMouseButtonCallback(m_window, WindowMouseButtonCallback);
    glfwSetCursorPosCallback(m_window, WindowMousePositionCallback);
    glfwSetScrollCallback(m_window, WindowScrollCallback);

    int gladLoaderStatus = gladLoaderLoadGL();
    ASSERT(!gladLoaderStatus);

    int flags;
    glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_TRUE);
        glDebugMessageCallback(Wongo::OpenGL::ErrorCallback, nullptr);
    }

    LOG_INFO_CORE("Using OpenGL version: %s", glGetString(GL_VERSION));

    glfwSwapInterval(1);
}

Wongo::WindowsWindow::~WindowsWindow()
{
    if (m_window)
    {
        glfwDestroyWindow(m_window);
    }
    glfwTerminate();
}

void Wongo::WindowsWindow::Update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

std::unique_ptr<Wongo::Window> Wongo::Window::Create(WindowProperties const& properties, Wongo::EventSystem& eventSystem)
{
    return std::make_unique<Wongo::WindowsWindow>(properties, eventSystem);
}
