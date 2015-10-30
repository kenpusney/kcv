
#ifndef __KCV_IMAGE_HPP
#define __KCV_IMAGE_HPP

#include "kcvBase.hpp"

namespace kcv
{
    class Image
    {
        typedef unsigned char byte;
        mutable kcv_image_t img;
        
        byte* GetRawDataAddress(int x, int y) const noexcept;
    public:
        Image(int x, int y, unsigned char* data, int color_size=4);
        
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