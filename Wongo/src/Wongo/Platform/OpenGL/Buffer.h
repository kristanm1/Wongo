#pragma once

#include "../../Renderer/Buffer.h"
#include <memory>

namespace Wongo::OpenGL
{

    class VertexArray;

    class VertexBuffer : public Wongo::VertexBuffer
    {
        friend class VertexArray;
    public:
        VertexBuffer(Description desc);
        ~VertexBuffer() override;

        void AddAttribute(int count, bool normalize = false) override;
    private:
        unsigned int m_vbo = 0;
        unsigned int m_type = 0;
        std::vector<Attribute> m_attributes{};
    };

    class IndexBuffer : public Wongo::IndexBuffer
    {
        friend class VertexArray;
    public:
        IndexBuffer(Description desc);
        ~IndexBuffer() override;

    private:
        unsigned int m_ebo;
        int m_type;
        int m_count;
    };

    class UniformBuffer : public Wongo::UniformBuffer
    {
    public:
        UniformBuffer(Description desc);
        ~UniformBuffer() override;

        void Set(int offset, int size, void const* data) override;
        void Bind(unsigned int index) override;
    private:
        unsigned int m_ubo;
    };

}
