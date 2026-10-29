#pragma once

#include <functional>
#include <memory>

namespace Wongo
{

    class Event;
    class EventSystem;

    struct WindowProperties
    {
        WindowProperties(
            std::string const& title = "Wongo engine",
            unsigned int width = 1280,
            unsigned int height = 720
        )
            : m_title(title)
            , m_width(width)
            , m_height(height)
        {}

        std::string m_title;
        unsigned int m_width;
        unsigned int m_height;
    };

    class Window
    {
    public:
        using EventCallback = std::function<void(Event const&)>;

        virtual ~Window() = default;

        virtual void Update() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void* GetNativeWindow() const = 0;

    public:
        // Defined in every platform window
        static std::unique_ptr<Window> Create(Wongo::WindowProperties const& properties, Wongo::EventSystem& eventSystem);
    };

}
