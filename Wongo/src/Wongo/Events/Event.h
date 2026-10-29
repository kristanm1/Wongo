#pragma once

#include "../Core.h"
#include <string>

namespace Wongo
{

    class Event
    {
    public:

        enum class Type
        {
            None = -1,
            WindowClose,
            WindowResize,
            KeyboardPressed,
            KeyboardReleased,
            MouseButtonPressed,
            MouseButtonReleased,
            MouseMoved,
            ScrollMove,
            Count,
        };

        virtual Type GetType() const = 0;
        virtual std::string ToString() const = 0;

        void Handle() const
        {
            m_isHandled = true;
        }

        bool IsHandled() const
        {
            return m_isHandled;
        }

    private:
        mutable bool m_isHandled = false;
    };

    class ButtonEvent : public Event
    {
    public:
        int GetScancode() const
        {
            return m_scancode;
        }

    protected:
        ButtonEvent(int scancode)
            : m_scancode(scancode)
        {}

        int m_scancode;
    };

}
