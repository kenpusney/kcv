
#ifndef __KCV_MAIN_IMAGE_WINDOW_HPP
#define __KCV_MAIN_IMAGE_WINDOW_HPP


#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>
#include <kcvImage.hpp>

using namespace kcv;

template<int XSIZE, int YSIZE>
class ImageWindow : public Fl_Double_Window
{
    unsigned char pixbuf[YSIZE][XSIZE][3];
    Image* img;

    void draw()
    {
        fl_draw_image((const uchar*)&pixbuf, 0, 0, XSIZE, YSIZE, 3, XSIZE*3);
    }

public:
    ImageWindow(Image& _image, const char *name=0) : Fl_Double_Window(_image.Width(), _image.Height() ,name),
                                                                          img(&_image)
    {
        end();
        RenderImage();
    }

    void PlotPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
    {
        pixbuf[y][x][0] = r;
        pixbuf[y][x][1] = g;
        pixbuf[y][x][2] = b;
    }

    void RenderImage()
    {
        
        for ( int y=0; y<img->Height(); y++ )
        {
            for ( int x=0; x<img->Width(); x++ )
            {
                unsigned char r,g,b;

                Color color = img->GetPixel(x, y);
                PlotPixel(x, y, color.r, color.g, color.b);
            }
        }
        redraw();
    }
};

#endif