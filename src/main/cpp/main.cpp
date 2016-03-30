#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>

#include "utils.hpp"
#include "ImageWindow.hpp"

#include <kcvTransformer.hpp>
#include <kcvFilter.hpp>
#include <vector>
#include <algorithm>
#include <iostream>

int main(int argc, char**argv)
{
    
    auto&& png = Fl_PNG_Image(argv[1]);

    Fl::visual(FL_RGB);         // prevents dithering on some systems
    

    auto img = transform(png);

    // std::vector<double> kernel {1, 2, 1, 2, 4, 2, 1, 2, 1}; 
    
    // kcv::Filter filter {1, kernel};
    
    // auto&& img1 = kcv::Processing(img, filter);
    
    MosaicTransform{10}.Transform(img);
    
    auto win = new ImageWindow<5000,5000>(img);
    win->show();
    Fl::run();
    delete win;
    return 0;
}