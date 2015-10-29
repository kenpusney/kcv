
#include <kcvImage.hpp>

using namespace kcv;
Image::byte* Image::GetRawDataAddress(int x, int y) const
{
    byte* start = img.data;
    int offset = img.width * y + x;
    return &start[offset*img.color_size];
}
        
Image::Image(int x, int y, unsigned char* data, int color_size)
{
    img.width = x;
    img.height = y;
    img.data = data;
    img.color_size = color_size;
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
    return color;
}

Color Image::GetPixel(const Point& point) const
{
    return GetPixel(point.x, point.y);
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
}

void Image::SetPixel(const Point& point, const Color& color)
{
    return SetPixel(point.x, point.y, color);
}

void Image::Free()
{
    kcvFreeImage(&img);
}

int Image::Width() const
{
    return img.width;
}

int Image::Height() const
{
    return img.height;
}