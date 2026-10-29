#include "EventSystem.h"

#include "../../Core.h"
#include "../../Logger.h"

void Wongo::EventSystem::Subscribe(std::string id, Wongo::EventSystem::EventCallback const& callback)
{
    for (auto const& callback : m_callbacks)
    {
        if (std::get<0>(callback) == id)
        {
            ASSERT(false);
            LOG_WARN_CORE("Skipped adding event with id: %s because it is already subscribed to event system!", id);
            return;
        }
    }

    m_callbacks.push_back({std::move(id), callback});
}

void Wongo::EventSystem::Unsubscribe(std::string const& id)
{
    auto it = std::find_if(m_callbacks.begin(), m_callbacks.end(), [&](auto const& c){ return std::get<0>(c) == id; });
    if (it != m_callbacks.end())
    {
        *it = m_callbacks.back();
        m_callbacks.pop_back();
    }
}

void Wongo::EventSystem::TriggerEvent(Event const& event)
{
    for (auto const& c : m_callbacks)
    {
        std::get<1>(c)(event);
    }
}
