
#ifndef __KCV_IMAGE_HPP
#define __KCV_IMAGE_HPP

#include "kcv_c.h"

namespace kcv
{
    
    using Color = kcv_color_t;
    using Point = kcv_point_t;
    
    class Image
    {
        typedef unsigned char byte;
        mutable kcv_image_t img;
        
        byte* GetRawDataAddress(int x, int y) const;
        
    public:
        Image(int x, int y, unsigned char* data, int color_size=4);
        
        Color GetPixel(int x, int y) const;
        
        Color GetPixel(const Point& point) const;
        
        void SetPixel(int x, int y, const Color& color);
        
        void SetPixel(const Point& point, const Color& color);
        
        void Free();
        
        int Width() const;
        
        int Height() const;
    };
}

#endif