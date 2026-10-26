#include "Wongo.h"

class TestLayer : public Wongo::Layer
{
public:

    void OnCreate(Wongo::Application& app) override;
    void OnUpdate() override;
    void RenderImGui() override;
    void OnEvent(Wongo::Event const& event) override;

private:
    glm::mat4 m_projection;
    glm::mat4 m_view;

    float m_x = 0;
    float m_y = 0;
    float m_z = 0;

    std::unique_ptr<Wongo::VertexBuffer> m_vb;
    std::unique_ptr<Wongo::IndexBuffer> m_ib;
    std::unique_ptr<Wongo::VertexArray> m_va;
    std::unique_ptr<Wongo::UniformBuffer> m_ub;
    std::unique_ptr<Wongo::Texture> m_texture;
    std::unique_ptr<Wongo::Program> m_program;
};