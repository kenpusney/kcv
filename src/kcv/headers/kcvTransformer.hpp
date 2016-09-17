
#ifndef __KCV_TRANSFORMER_HPP
#define __KCV_TRANSFORMER_HPP

#include "kcvImage.hpp"

namespace kcv
{
    template<class PixelConverter>
    class PixelTransformer
    {
    public:
        void Transform(Image& image);
    };
    
    template<class PixelConverter>
    void PixelTransformer<PixelConverter>::Transform(Image& image)
    {
        auto converter = PixelConverter{};
        for(int x = 0; x < image.Width(); x++)
        {
            for(int y = 0; y < image.Height(); y++)
            {
                image.SetPixel(x, y, converter(image.GetPixel(x, y)));
            }
        }
    }

    namespace converter {

        class GrayPixelConverter
        {
        public:
            Color operator()(const Color& color) const
            {
                int gray = (color.r*30 + color.g*59 + color.b*11) / 100;
                return Color {gray, gray, gray, gray, color.size};
            }
        };

        class BinaryPixelConverter
        {
        public:
            Color operator()(const Color& color) const
            {
                int average = (color.r + color.g + color.b) / 3;
                int binary = (average > 100) ? 255 : 0;
                return Color {binary, binary, binary, binary, color.size};
            }
        };

        class InversePixelConverter
        {
        public:
            Color operator()(const Color& color) const 
            {
                return Color { 255 - color.r, 255 - color.g, 255 - color.b, 255 - color.a, color.size };
            }
        };

    }


    using GrayTransform = PixelTransformer<converter::GrayPixelConverter>;
    using BinaryTransform = PixelTransformer<converter::BinaryPixelConverter>;
    using InverseTransform = PixelTransformer<converter::InversePixelConverter>;

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