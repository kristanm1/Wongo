#pragma once

#include "Event.h"

namespace Wongo
{

    class MouseButtonPressedEvent : public ButtonEvent
    {
    public:
        MouseButtonPressedEvent(int scancode)
            : ButtonEvent(scancode)
        {}

        Type GetType() const override
        {
            return Type::MouseButtonPressed;
        }

        std::string ToString() const override
        {
            return (std::stringstream{} << "MouseButtonPressedEvent(scancode: " << m_scancode << ")").str();
        }
    };

    class MouseButtonReleasedEvent : public ButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int scancode)
            : ButtonEvent(scancode)
        {}

        Type GetType() const override
        {
            return Type::MouseButtonReleased;
        }

        std::string ToString() const override
        {
            return (std::stringstream{} << "MouseButtonReleasedEvent(scancode: " << m_scancode << ")").str();
        }
    };

    class MouseMoveEvent : public Event
    {
    public:
        MouseMoveEvent(float xpos, float ypos)
            : m_xpos(xpos)
            , m_ypos(ypos)
        {}

        Type GetType() const override
        {
            return Type::MouseMoved;
        }

        std::string ToString() const override
        {
            return (std::stringstream{} << "MouseMoveEvent(xpos: " << m_xpos << ", ypos: " << m_ypos << ")").str();
        }

    private:
        float m_xpos;
        float m_ypos;
    };

}
