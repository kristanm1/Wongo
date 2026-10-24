#pragma once

#include "Event.h"
#include <string>
#include <sstream>

namespace Wongo
{

    class KeyboardPressedEvent : public ButtonEvent
    {
    public:
        KeyboardPressedEvent(int scancode, int repeat)
            : ButtonEvent(scancode)
            , m_repeat(repeat)
        {}

        EVENT_GET_TYPE(KeyboardPressed);
        EVENT_GET_CATEGORY(EventCategory::ButtonEvent | EventCategory::KeyboardEvent);

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent(KeyCode: " << m_scancode << ", KeyRepeat: " << m_repeat << ")";
            return ss.str();
        }

    private:
        int m_repeat;
    };

    class KeyboardReleasedEvent : public ButtonEvent
    {
    public:
        KeyboardReleasedEvent(int scancode)
            : ButtonEvent(scancode)
        {}

        EVENT_GET_TYPE(KeyboardReleased);
        EVENT_GET_CATEGORY(EventCategory::ButtonEvent | EventCategory::KeyboardEvent);

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent(" << m_scancode << ")";
            return ss.str();
        }
    };

}
