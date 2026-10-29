#pragma once

#include "Event.h"

namespace Wongo
{

    class ScrollMoveEvent : public Event
    {
    public:
    ScrollMoveEvent(float xoffset, float yoffset)
        : m_xoffset(xoffset)
        , m_yoffset(yoffset)
    {}

    Type GetType() const override
    {
        return Type::ScrollMove;
    }

    std::string ToString() const override
    {
        return (std::stringstream{} << "ScrollEvent(xoffset: " << m_xoffset << ", yoffset: " << m_yoffset << ")").str();
    }

    private:
        float m_xoffset;
        float m_yoffset;
    };

}
