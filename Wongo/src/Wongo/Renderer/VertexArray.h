#pragma once

#include "Core.h"
#include "Buffer.h"

namespace Wongo
{

    class VertexBuffer;
    class IndexBuffer;

    class VertexArray : private Wongo::RenderObjectBase
    {
    public:
        static std::shared_ptr<VertexArray> Create();

        virtual void AddVertexBuffer(std::shared_ptr<Wongo::VertexBuffer> const& buffer) = 0;
        virtual void SetIndexBuffer(std::shared_ptr<Wongo::IndexBuffer> const& index) = 0;

        virtual int GetIndexCount() const = 0;
        virtual unsigned int GetIndexType() const = 0;
        
        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;
    };

}