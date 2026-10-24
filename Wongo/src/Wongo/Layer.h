#pragma once

#include "Events/Event.h"

namespace Wongo
{

    class Application;

    class Layer
    {
    public:
        virtual ~Layer() = default;
        virtual void OnCreate(Application& app) {};
        virtual void OnDestroy() {}; // to-do: not called yet..
        virtual void OnUpdate() {};
        virtual void RenderImGui() {};
        virtual void OnEvent(Wongo::Event const& event) {}
    };

}