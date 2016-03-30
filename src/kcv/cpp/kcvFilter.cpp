
#include "kcvFilter.hpp"
#include <algorithm>
#include <iostream>

using std::max;
using std::min;

namespace kcv
{
    
    Filter::Filter(int radius, const std::vector<double>& data):
    kernel {radius, data}
    {
    }
    
    int Filter::Radius() const
    {
        return kernel.radius;
    }
    
    double Filter::Get(int x, int y) const
    {
        x += kernel.radius;
        y += kernel.radius;
        return kernel.data[kernel.radius*2*y + x];
    }
    
    void Filter::Set(int x, int y, double value)
    {
        x += kernel.radius;
        y += kernel.radius;
        kernel.data[kernel.radius*2*y + x] = value;
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
    
    void adjust(int r)
    {
        if (r > 255)
        {
            r = 255;
        } else if (r < 0)
        {
            r = 0;
        }
    }
        
    void adjust(Color& color) 
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
                for(int j = -filter.Radius(); j < filter.Radius(); j++)
                {
                    for(int i = -filter.Radius(); i < filter.Radius(); i++)
                    {
                        auto weight = filter.Get(i, j);
                        auto current = image.GetPixel(Edge(i, x, width), Edge(j, y, height));
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