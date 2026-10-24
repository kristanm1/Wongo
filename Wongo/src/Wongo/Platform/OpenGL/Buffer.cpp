#include "../../Logger.h"
#include "Core.h"
#include "Buffer.h"

#include <glad/gl.h>

// Vertex

Wongo::OpenGL::VertexBuffer::VertexBuffer(Description desc)
    : m_type(Wongo::OpenGL::GetDataType(desc.dataType))
{
    GLCall(glCreateBuffers(1, &m_vbo));
    GLCall(glNamedBufferData(m_vbo, desc.size, desc.data, GL_STATIC_DRAW));
}

Wongo::OpenGL::VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_vbo));
}

void Wongo::OpenGL::VertexBuffer::AddAttribute(int count, bool normalize)
{
    m_attributes.push_back({count, normalize});
}

// Index

Wongo::OpenGL::IndexBuffer::IndexBuffer(Description desc)
    : m_count(desc.count)
    , m_type(Wongo::OpenGL::GetDataType(desc.dataType))
{
    GLCall(glCreateBuffers(1, &m_ebo));
    GLCall(glNamedBufferData(m_ebo, desc.count * Wongo::GetDataTypeSize(desc.dataType), desc.data, GL_STATIC_DRAW));
}

Wongo::OpenGL::IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_ebo));
}

// Uniform

Wongo::OpenGL::UniformBuffer::UniformBuffer(Description desc)
{
    GLCall(glCreateBuffers(1, &m_ubo));
    GLCall(glNamedBufferData(m_ubo, desc.size, nullptr, GL_DYNAMIC_DRAW));
}

Wongo::OpenGL::UniformBuffer::~UniformBuffer()
{
    GLCall(glDeleteBuffers(1, &m_ubo));
}

void Wongo::OpenGL::UniformBuffer::Set(int offset, int size, void const* data)
{
    GLCall(glNamedBufferSubData(m_ubo, offset, size, data));
}

void Wongo::OpenGL::UniformBuffer::Bind(unsigned int index)
{
    GLCall(glBindBufferBase(GL_UNIFORM_BUFFER, index, m_ubo));
}
