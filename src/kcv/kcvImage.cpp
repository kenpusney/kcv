
#include "kcvImage.hpp"
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

namespace kcv
{
    
    Image::byte* Image::GetRawDataAddress(int x, int y) const noexcept
    {
        int offset = img.width * y + x;
        return &img.data[offset*img.color_size];
    }
    
    Image::Image(int x, int y, const std::vector<Image::byte>& data, int color_size):
    img {x, y, data, color_size}
    {
    }
    
    Color Image::GetPixel(int x, int y) const
    {
        Color color;
        byte* start = GetRawDataAddress(x, y);
        if(img.color_size == 1) // 8bit
        {
            color.r = color.b = color.g = start[0];
            color.size = img.color_size;
        }
        else if (img.color_size == 4)
        {
            color.r = start[0];
            color.g = start[1];
            color.b = start[2];
            color.a = start[3];
            color.size = img.color_size;
        }
        else if (img.color_size == 3) {
            color.r = start[0];
            color.g = start[1];
            color.b = start[2];
            color.size = img.color_size;
        }
        return color;
    }
    
    Color Image::GetPixel(const Point2D& point) const
    {
        return GetPixel(point.x, point.y);
    }
    
    Image::Image(const Image& image): Image{image.img.width, image.img.height, image.img.data, image.img.color_size}
    {
    }
    
    void Image::SetPixel(int x, int y, const Color& color)
    {
        byte* start = GetRawDataAddress(x, y);
        
        if(img.color_size == 1)
        {
            start[0] = color.r;
        }
        else if (img.color_size == 4)
        {
            start[0] = color.r;
            start[1] = color.g;
            start[2] = color.b;
            start[3] = color.a;
        }
        else if (img.color_size == 3) {
            start[0] = color.r;
            start[1] = color.g;
            start[2] = color.b;
        }
    }
    
    void Image::SetPixel(const Point2D& point, const Color& color)
    {
        return SetPixel(point.x, point.y, color);
    }
    
    int Image::ColorSize() const
    {
        return img.color_size;
    }
    
    int Image::Width() const
    {
        return img.width;
    }
    
    int Image::Height() const
    {
        return img.height;
    }
}