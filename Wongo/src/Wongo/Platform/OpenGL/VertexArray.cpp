#include "VertexArray.h"
#include "Core.h"
#include "Buffer.h"
#include "../../Logger.h"

Wongo::OpenGL::VertexArray::VertexArray()
    : m_bindingIndex(0)
    , m_attribLocation(0)
{
    GLCall(glCreateVertexArrays(1, &m_vao));
}

Wongo::OpenGL::VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &m_vao));
}

void Wongo::OpenGL::VertexArray::AddVertexBuffer(Wongo::VertexBuffer *buffer)
{
    VertexBuffer const* pBuffer = static_cast<VertexBuffer*>(buffer);

    int offset = 0;
    int typeSize = GetDataTypeSize(pBuffer->m_type);
    for (auto const& attribute : pBuffer->m_attributes)
    {
        GLCall(glEnableVertexArrayAttrib(m_vao, m_attribLocation));
        GLCall(glVertexArrayAttribFormat(m_vao, m_attribLocation, attribute.count, pBuffer->m_type, Wongo::OpenGL::GetBoolType(attribute.normalize), offset));
        GLCall(glVertexArrayAttribBinding(m_vao, m_attribLocation, m_bindingIndex));
        offset += attribute.count * typeSize;
        m_attribLocation++;
    }
    GLCall(glVertexArrayVertexBuffer(m_vao, m_bindingIndex, pBuffer->m_vbo, 0, offset));
    m_bindingIndex++;
}

void Wongo::OpenGL::VertexArray::SetIndexBuffer(Wongo::IndexBuffer *index)
{
    IndexBuffer const* pIndex = static_cast<IndexBuffer*>(index);

    GLCall(glVertexArrayElementBuffer(m_vao, pIndex->m_ebo));
    m_indexCount = pIndex->m_count;
    m_indexType = pIndex->m_type;
}

void Wongo::OpenGL::VertexArray::Bind() const
{
    GLCall(glBindVertexArray(m_vao));
}

void Wongo::OpenGL::VertexArray::UnBind() const
{
    GLCall(glBindVertexArray(0));
}
