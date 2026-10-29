#ifndef _EVENT_SYSTEM_
#define _EVENT_SYSTEM_

#include "../../Events/Event.h"

#include <functional>
#include <vector>
#include <tuple>

namespace Wongo
{

    class EventSystem
    {
    public:

        using EventCallback = std::function<void(Event const&)>;

        void Subscribe(std::string id, EventCallback const& callback);
        void Unsubscribe(std::string const& id);

        void TriggerEvent(Event const& event);

    private:
        std::vector<std::tuple<std::string, EventCallback>> m_callbacks{};
    };

}

#endif
