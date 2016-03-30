
#ifndef __KCV_IMAGE_HPP
#define __KCV_IMAGE_HPP

#include "kcvBase.hpp"
#include <vector>

namespace kcv
{
    class Image
    {
        typedef unsigned char byte;
        mutable struct
        {
            int width;
            int height;
            std::vector<byte> data;
            int color_size;
        } img;
        
        byte* GetRawDataAddress(int x, int y) const noexcept;
    public:
        Image(int x, int y, const std::vector<byte>& data, int color_size=4);
        Image(const Image& image);
        
        Color GetPixel(int x, int y) const;
        Color GetPixel(const Point2D& point) const;
        void SetPixel(int x, int y, const Color& color);
        void SetPixel(const Point2D& point, const Color& color);
        
        int ColorSize() const;
        int Width() const;
        int Height() const;
        
        void Free();
        Image Clone() const;
    };
}

#endif