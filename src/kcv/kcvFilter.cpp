
#include "kcvFilter.hpp"
#include <algorithm>
#include <iostream>

using std::max;
using std::min;

namespace kcv
{
    
    Filter::Filter(int size, const std::vector<double>& data):
    kernel {size, data}
    {
    }
    
    int Filter::Size() const
    {
        return kernel.size;
    }
    
    double Filter::Get(int x, int y) const
    {
        return kernel.data[kernel.size*y + x];
    }
    
    void Filter::Set(int x, int y, double value)
    {
        kernel.data[kernel.size*y + x] = value;
    }
    
    void Filter::Set(int index, double value)
    {
        kernel.data[index] = value;
    }
    
    int Edge(int offset, int start, int width)
    {
        if(offset > 0) return min(start+offset, width-1);
        if(offset < 0) return max(start+offset, 0);
        return offset;
    }
    
    static void adjust(int& r)
    {
        if (r > 255)
        {
            r = 255;
        } else if (r < 0)
        {
            r = 0;
        }
    }
        
    static void adjust(Color& color) 
    {
        adjust(color.r);
        adjust(color.g);
        adjust(color.b);
        adjust(color.a);
    }

    Image Processing(const Image& image, const Filter& filter)
    {
        Image snap {image};
        int width = image.Width();
        int height = image.Height();
        
        
        for(int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
            {
                Color color {0, 0, 0, 0, image.ColorSize()};
                for(int j = 0; j < filter.Size(); j++)
                {
                    for(int i = 0; i < filter.Size(); i++)
                    {
                        auto weight = filter.Get(i, j);
                        auto current = image.GetPixel(Edge(i - filter.Size(), x, width), Edge(j - filter.Size(), y, height));
                        color.r += current.r * weight;
                        color.g += current.g * weight;
                        color.b += current.b * weight;
                        color.a += current.a * weight;
                        adjust(color);
                    }
                }
                
                snap.SetPixel(x, y, Color {color.r,
                    color.g,
                    color.b,
                    color.a, image.ColorSize()});
            }
        }
        
        return snap;
    }
    
}