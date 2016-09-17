
#ifndef __KCV_FILTER_HPP
#define __KCV_FILTER_HPP

#include "kcvImage.hpp"
#include <vector>

namespace kcv
{
    struct FilterKernel
    {
        int size;
        std::vector<double> data;
    };
    
    class Filter
    {
        FilterKernel kernel;
        
    public:
        Filter(int size, const std::vector<double>& data);
        
        
        int Size() const;
        double Get(int x, int y) const;
        
        void Set(int x, int y, double value);
        void Set(int index, double value);
    };
    
    int Edge(int offset, int start, int width);
    
    Image Processing(const Image& image, const Filter& filter);
}

#endif