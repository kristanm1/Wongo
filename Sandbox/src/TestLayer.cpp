#include "TestLayer.h"

void TestLayer::OnCreate(Wongo::Application& app)
{
    std::vector<float> vertexData;
    std::vector<unsigned int> indices;
    std::string texturePath;

    std::string assetPath = WONGO_RESOURCE_DIR + std::string("/asset/");
    Wongo::LoadObj(assetPath, std::string("globe.obj"), vertexData, indices, texturePath);

    m_texture = Wongo::Texture::Create({ assetPath + "earthmap.jpg" });

    m_vb = Wongo::VertexBuffer::Create({
        static_cast<int>(vertexData.size() * sizeof(float)),
        Wongo::DataType::Float,
        vertexData.data()
    });
    m_vb->AddAttribute(3);
    m_vb->AddAttribute(3);
    m_vb->AddAttribute(2);

    m_ib = Wongo::IndexBuffer::Create({
        static_cast<int>(indices.size()),
        Wongo::DataType::UnsignedInt,
        indices.data()
    });

    m_va = Wongo::VertexArray::Create();
    m_va->AddVertexBuffer(m_vb);
    m_va->SetIndexBuffer(m_ib);

    std::shared_ptr<Wongo::Shader> vs = Wongo::Shader::Create({
        Wongo::Shader::Type::Vertex,
        Wongo::Shader::Description::ContentType::Path,
        WONGO_RESOURCE_DIR + std::string("/shader/vShader.glsl")
    });

    std::shared_ptr<Wongo::Shader> fs = Wongo::Shader::Create({
        Wongo::Shader::Type::Fragment,
        Wongo::Shader::Description::ContentType::Path,
        WONGO_RESOURCE_DIR + std::string("/shader/fShader.glsl")
    });

    m_program = Wongo::Program::Create();
    m_program->AttachShader(vs);
    m_program->AttachShader(fs);
    m_program->Link();

    //projection = glm::ortho(-4.0f, 4.0f, -4.0f, 4.0f, -1.0f, 100.0f);
    m_projection = glm::perspective(
        glm::radians(45.0f),
        static_cast<float>(app.GetWindow().GetWidth()) / static_cast<float>(app.GetWindow().GetHeight()),
        0.1f, 100.0f);

    m_view = glm::lookAt(glm::vec3(0.0f, 0.0f, 4.0f), glm::vec3(), glm::vec3(0.0f, 1.0f, 0.0f));

    m_ub = Wongo::UniformBuffer::Create({static_cast<int>(2 * sizeof(glm::mat4))});
    m_ub->Set(0, sizeof(glm::mat4), glm::value_ptr(m_projection));
    m_ub->Set(sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(m_view));
    m_ub->Bind(0);
}

void TestLayer::OnUpdate()
{
    Wongo::Renderer::SetColor(0.2f, 0.2f, 0.2f, 1.0f);
    Wongo::Renderer::Clear(Wongo::Backend::ClearMask::Color | Wongo::Backend::ClearMask::Depth);
    Wongo::Renderer::EnableDepthTest(true);
    Wongo::Renderer::CullFace(Wongo::Backend::CullFaces::Back);
    
    glm::mat4 model = glm::rotate(
        glm::rotate(
            glm::rotate(glm::mat4(1.0f), glm::radians(m_y), glm::vec3(0.0f, 1.0f, 0.0f)),
            glm::radians(m_x), glm::vec3(1.0f, 0.0f, 0.0f)
        ),
        glm::radians(m_z), glm::vec3(0.0f, 0.0f, 1.0f)
    );

    m_texture->Bind(0);

    m_program->Use();
    m_program->SetInt("u_texture", 0);
    m_program->SetFloatMat4("u_model", model);

    Wongo::Renderer::DrawElements(*m_va);
}

void TestLayer::RenderImGui()
{
    ImGui::Begin("TestWindow");

    ImVec2 pos;

    pos = ImGui::GetCursorPos();
    ImGui::SetCursorPos(ImVec2(20 + pos.x, pos.y));
    ImGui::SliderFloat("Rotation X", &m_x, -180.0f, 180.0f, "%.1f");

    pos = ImGui::GetCursorPos();
    ImGui::SetCursorPos(ImVec2(20 + pos.x, pos.y));
    ImGui::SliderFloat("Rotation Y", &m_y, -180.0f, 180.0f, "%.1f");

    pos = ImGui::GetCursorPos();
    ImGui::SetCursorPos(ImVec2(20 + pos.x, pos.y));
    ImGui::SliderFloat("Rotation Z", &m_z, -180.0f, 180.0f, "%.1f");

    ImGui::End();
}

void TestLayer::OnEvent(Wongo::Event const& event)
{
    if (event.GetType() == Wongo::EventType::WindowResize)
    {
        auto const& resizeEvent = reinterpret_cast<Wongo::WindowResizeEvent const&>(event);
        m_projection = glm::perspective(
            glm::radians(45.0f),
            static_cast<float>(resizeEvent.GetWidth()) / static_cast<float>(resizeEvent.GetHeight()),
            0.1f, 100.0f);
    }
}