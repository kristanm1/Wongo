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
        static std::unique_ptr<VertexArray> Create();

        virtual void AddVertexBuffer(Wongo::VertexBuffer *buffer) = 0;
        virtual void SetIndexBuffer(Wongo::IndexBuffer *index) = 0;

        virtual int GetIndexCount() const = 0;
        virtual unsigned int GetIndexType() const = 0;
        
        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;
    };

}