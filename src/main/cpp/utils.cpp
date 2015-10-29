
#include "utils.hpp"
#include <stdio.h>

using namespace kcv;

typedef unsigned char byte;

Image transform(const Fl_PNG_Image& png)
{
    byte* data = new byte[png.w()*png.h()*4];
    int offset = 0;
    auto base = png.data()[0];
    
    for(int i = 0; i < png.w(); i++)
    {
        for(int j = 0; j < png.h(); j++)
        {
            for(int o = 0; o < 4; o++)
            {
                data[offset*4+o] = base[offset*png.d()+o];
            }
            offset++;
        } 
    }
    return Image {png.w(), png.h(), data};
}
