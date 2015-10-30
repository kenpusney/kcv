
#ifndef __KCV_FILTER_HPP
#define __KCV_FILTER_HPP

#include "kcvImage.hpp"
#include "kcv_c_filter.h"

namespace kcv
{
    class Filter
    {
        kcv_filter_t kernel;
        
    public:
        Filter(int radius, double* data);
        
        
        int Radius() const;
        double Get(int x, int y) const;
        
        void Set(int x, int y, double value);
        void Set(int index, double value);
    };
    
    int Edge(int offset, int start, int width);
    
    Image Processing(Image& image, Filter& filter);
}

#endif