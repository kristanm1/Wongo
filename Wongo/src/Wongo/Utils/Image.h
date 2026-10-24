#ifndef _IMAGE_
#define _IMAGE_

#include <string>

namespace Wongo
{

    class Image
    {
    public:

        struct Description
        {
            std::string path{};
            bool flipVerticalOnLoad = true;
        };

        Image(Description desc);
        Image(Image&& other) noexcept;
        ~Image();
        Image& operator=(Image&& other) noexcept;

        Image(Image const&) = delete;
        Image& operator=(Image const&) = delete;

        unsigned char const* GetPixels() const { return m_pixels; }
        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }
        int GetChannels() const { return m_channels; }

    private:
        int m_width;
        int m_height;
        int m_channels;
        unsigned char* m_pixels = nullptr;
    };

}

#endif
