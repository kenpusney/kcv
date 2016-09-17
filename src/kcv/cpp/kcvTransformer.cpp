
#include "kcvTransformer.hpp"
#include "kcvImage.hpp"

#include <stdio.h>

namespace kcv
{
    
    MosaicTransform::MosaicTransform(int _level): level(_level)
    {
    }
    
    void MosaicTransform::CreateMosaicForTile(int horizonal, int vertical, Image& image)
    {
        int x = horizonal * level;
        int y = vertical * level;

        int median_x = x + level/2, median_y = y + level/2;
        
        if(median_x >= image.Width() || median_y >= image.Height())
        {
            median_x = x - 1;
            median_y = y - 1;
        }
        
        auto mosaic = image.GetPixel(median_x, median_y);
        
        for(int i = x; i < x+level; i++)
        {
            if(i >= image.Width()) break;
            for(int j = y; j < y+level; j++)
            {
                if(j >= image.Height()) break;
                image.SetPixel(i, j, mosaic);
            }
        }
    }
    
    void MosaicTransform::Transform(Image& image)
    {
        int horizonal_tiles = image.Width() / level + 1;
        int vertical_tiles = image.Height() / level + 1;
        
        for(int h = 0; h < horizonal_tiles; h++)
        {
            for(int v = 0; v < vertical_tiles; v++)
            {
                CreateMosaicForTile(h, v, image);
            }
        }
    }
}