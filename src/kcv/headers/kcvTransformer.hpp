
#ifndef __KCV_TRANSFORMER_HPP
#define __KCV_TRANSFORMER_HPP

#include "kcvImage.hpp"

namespace kcv
{
    class GrayTransform
    {     
        Color Grayfy(const Color& color);
    public:
        void Transform(Image& image);
    };
    
    class MosaicTransform
    {
        int level;
        void CreateMosaicForTile(int horizonal, int vertical, Image& image);
    public:
        MosaicTransform(int _level=8);
        void Transform(Image& image);
    };
}

#endif