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

        EVENT_GET_TYPE(MouseButtonPressed);
        EVENT_GET_CATEGORY(EventCategory::ButtonEvent | EventCategory::MouseEvent);

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent(scancode: " << m_scancode << ")";
            return ss.str();
        }
    };

    class MouseButtonReleasedEvent : public ButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int scancode)
            : ButtonEvent(scancode)
        {}

        EVENT_GET_TYPE(MouseButtonReleased);
        EVENT_GET_CATEGORY(EventCategory::ButtonEvent | EventCategory::MouseEvent);

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent(scancode: " << m_scancode << ")";
            return ss.str();
        }
    };

    class MouseMoveEvent : public Event
    {
    public:
        MouseMoveEvent(double xpos, double ypos)
            : m_xpos(xpos)
            , m_ypos(ypos)
        {}

        EVENT_GET_TYPE(MouseMoved);
        EVENT_GET_CATEGORY(EventCategory::MouseEvent);

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMoveEvent(xpos: " << m_xpos << ", ypos: " << m_ypos << ")";
            return ss.str();
        }

    private:
        double m_xpos;
        double m_ypos;
    };

}
