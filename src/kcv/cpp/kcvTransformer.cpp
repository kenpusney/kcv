
#include <kcvTransformer.hpp>
#include <kcvImage.hpp>

#include <stdio.h>

namespace kcv
{
    
    Color GrayTransform::Grayfy(const Color& color)
    {
        int gray = (color.r*30 + color.g*59 + color.b*11) / 100;
        return Color {gray, gray, gray, gray, color.size};
    }
    
    void GrayTransform::Transform(Image& image)
    {
        for(int x = 0; x < image.Width(); x++)
        {
            for(int y = 0; y < image.Height(); y++)
            {
                image.SetPixel(x, y, Grayfy(image.GetPixel(x, y)));
            }
        }
    }
    
    MosaicTransform::MosaicTransform(int _level): level(_level)
    {
    }
    
    void MosaicTransform::CreateMosaicForTile(int horizonal, int vertical, Image& image)
    {
        int x = horizonal * level;
        int y = vertical * level;
        int pix_count = level*level;
        
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