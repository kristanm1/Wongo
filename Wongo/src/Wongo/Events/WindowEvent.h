#pragma once

#include "Event.h"
#include <string>
#include <sstream>

namespace Wongo
{

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent()
        {}

        Type GetType() const override
        {
            return Type::WindowClose;
        }

        std::string ToString() const override
        {
            return "WindowCloseEvent";
        }
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(int width, int height)
            : m_width(width)
            , m_height(height)
        {}

        int GetWidth() const
        {
            return m_width;
        }

        int GetHeight() const
        {
            return m_height;
        }

        Type GetType() const override
        {
            return Type::WindowResize;
        }

        std::string ToString() const override
        {
            return (std::stringstream{} << "WindowResizeEvent(Width: " << m_width << ", Height: " << m_height << ")").str();
        }

    private:
        int m_width;
        int m_height;
    };

}
