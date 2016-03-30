
#include "utils.hpp"
#include <vector>

using namespace kcv;

typedef unsigned char byte;

Image transform(const Fl_PNG_Image& png)
{
    std::vector<byte> data;
    data.reserve(png.w()* png.h()* 4+1);
    
    auto base = png.data()[0];
    
    std::copy_n(base, png.d()*png.h()*png.w(), std::back_inserter(data));
    
    return Image {png.w(), png.h(), data, png.d()};
}
