#pragma once

#include "../Core.h"
#include <string>

namespace Wongo
{

    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize,
        KeyboardPressed, KeyboardReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved,
        Scroll,
    };

    enum EventCategory
    {
        None = 0,
        WindowEvent = BIT(0),
        ButtonEvent = BIT(1),
        KeyboardEvent = BIT(2),
        MouseEvent = BIT(3),
        ScrollEvent = BIT(4),

        InputEvent = ButtonEvent | KeyboardEvent | MouseEvent | ScrollEvent,
    };

    class Event
    {
    public:
        virtual EventType GetType() const = 0;
        virtual EventCategory GetCatergory() const = 0;
        virtual std::string ToString() const = 0;

        void Handle() const { m_isHandled = true; }
        bool IsHandled() const { return m_isHandled; }

        bool IsInCategory(EventCategory category) const { return GetCatergory() & category; }

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

#define EVENT_GET_TYPE(event_type) EventType GetType() const override \
    { return EventType::event_type; }

#define EVENT_GET_CATEGORY(event_category) EventCategory GetCatergory() const override \
    { return static_cast<EventCategory>(event_category); }

}
