#pragma once

#include "Event.h"

namespace Wongo
{

    class ScrollMoveEvent : public Event
    {
    public:
    ScrollMoveEvent(double xoffset, double yoffset)
        : m_xoffset(xoffset)
        , m_yoffset(yoffset)
    {}

    EVENT_GET_CATEGORY(EventCategory::ScrollEvent);
    EVENT_GET_TYPE(Scroll);

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "ScrollEvent(xoffset: " << m_xoffset << ", yoffset: " << m_yoffset << ")";
        return ss.str();
    }

    private:
        double m_xoffset;
        double m_yoffset;
    };

}
