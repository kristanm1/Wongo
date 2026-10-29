#pragma once

#include "Event.h"
#include <string>
#include <sstream>

namespace Wongo
{

    class KeyboardPressedEvent : public ButtonEvent
    {
    public:
        KeyboardPressedEvent(int scancode, bool repeat)
            : ButtonEvent(scancode)
            , m_repeat(repeat)
        {}

        Type GetType() const override
        {
            return Type::KeyboardPressed;
        }

        std::string ToString() const override
        {
            return (std::stringstream{} << "KeyPressedEvent(KeyCode: " << m_scancode << ", KeyRepeat: " << m_repeat << ")").str();
        }

    private:
        bool m_repeat;
    };

    class KeyboardReleasedEvent : public ButtonEvent
    {
    public:
        KeyboardReleasedEvent(int scancode)
            : ButtonEvent(scancode)
        {}

        Type GetType() const override
        {
            return Type::KeyboardReleased;
        }

        std::string ToString() const override
        {
            return (std::stringstream{} << "KeyReleasedEvent(" << m_scancode << ")").str();
        }
    };

}
