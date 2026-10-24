#pragma once

#include "../../Renderer/VertexArray.h"

namespace Wongo::OpenGL
{

    class VertexBuffer;
    class BufferLayout;
    class IndexBuffer;

    int TypeSize(unsigned int type); // can this be removed?

    class VertexArray : public Wongo::VertexArray
    {
    public:
        VertexArray();
        ~VertexArray() override;

        void AddVertexBuffer(std::shared_ptr<Wongo::VertexBuffer> const& buffer) override;
        void SetIndexBuffer(std::shared_ptr<Wongo::IndexBuffer> const& index) override;

        int GetIndexCount() const override { return m_indexCount; }
        unsigned int GetIndexType() const override { return m_indexType; }
        
        void Bind() const override;
        void UnBind() const override;
    private:
        unsigned int m_vao;
        unsigned int m_indexType;
        int m_attribLocation;
        int m_bindingIndex;
        int m_indexCount;
    };

}