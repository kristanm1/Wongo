#include "TestLayer.h"
#define WONGO_ENTRY_POINT
#include "Wongo.h"

class Sandbox : public Wongo::Application
{
public:
    Sandbox() : Application()
    {
        LOG_INFO_CLIENT("Created Sandbox!");
        PushLayer<TestLayer>();
    }

    ~Sandbox()
    {

    }
};

Wongo::Application* Wongo::CreateApplication()
{
    return new Sandbox();
}