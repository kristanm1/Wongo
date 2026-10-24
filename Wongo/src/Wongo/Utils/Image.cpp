#include "Image.h"
#include "../Core.h"
#include "../Logger.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

Wongo::Image::Image(Description desc)
{
    stbi_set_flip_vertically_on_load(desc.flipVerticalOnLoad);
    m_pixels = stbi_load(desc.path.c_str(), &m_width, &m_height, &m_channels, 3);

    ASSERT(!m_pixels);
    if (!m_pixels)
    {
        LOG_ERROR_CORE("Loading image %s failed!", desc.path.c_str());
    }
}

Wongo::Image::Image(Image&& other) noexcept
    : m_width(other.m_width)
    , m_height(other.m_height)
    , m_channels(other.m_channels)
    , m_pixels(other.m_pixels)
{
    other.m_width = 0;
    other.m_height = 0;
    other.m_channels = 0;
    other.m_pixels = nullptr;
}

Wongo::Image::~Image()
{
    stbi_image_free(m_pixels);
}

Wongo::Image& Wongo::Image::operator=(Image&& other) noexcept
{
    if (this != &other)
    {
        stbi_image_free(m_pixels);
        m_width = other.m_width;
        m_height = other.m_height;
        m_channels = other.m_channels;
        m_pixels = other.m_pixels;

        other.m_width = 0;
        other.m_height = 0;
        other.m_channels = 0;
        other.m_pixels = nullptr;
    }

    return *this;
}
