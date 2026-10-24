#pragma once

#include "Event.h"
#include <string>
#include <sstream>

namespace Wongo
{

    class WindowEvent : public Event
    {
    public:
        EVENT_GET_CATEGORY(EventCategory::WindowEvent);
    protected:
        WindowEvent()
        {}
    };

    class WindowCloseEvent : public WindowEvent
    {
    public:
        WindowCloseEvent()
        {}

        EVENT_GET_TYPE(WindowClose);

        std::string ToString() const override
        {
            return "WindowCloseEvent";
        }
    };

    class WindowResizeEvent : public WindowEvent
    {
    public:
        WindowResizeEvent(int width, int height)
            : m_width(width)
            , m_height(height)
        {}

        EVENT_GET_TYPE(WindowResize);

        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent(Width: " << m_width << ", Height: " << m_height << ")";
            return ss.str();
        }

    private:
        int m_width;
        int m_height;
    };

}
