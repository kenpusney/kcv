
#ifndef __KCV_C_H
#define __KCV_C_H

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

typedef struct kcv_point2d_t
{
    int x;
    int y;
} kcv_point2d_t;

typedef struct kcv_line2d_t
{
    kcv_point2d_t from;
    kcv_point2d_t to;
} kcv_line2d_t;

typedef struct kcv_point2d_t kcv_vec2d_t;

typedef struct kcv_image_t
{
    int width;
    int height;
    int color_size;
    unsigned char* data; 
} kcv_image_t;

typedef struct kcv_color_t
{
    int size;
    int r;
    int g;
    int b;
    int a;
} kcv_color_t;

int kcvFreeImage(kcv_image_t* img);

kcv_color_t kcvGetPixel(kcv_image_t* img, int x, int y);

void kcvSetPixel(kcv_image_t* img, kcv_color_t color, int x, int y);

#ifdef __cplusplus
}  // extern "C"
#endif // __cplusplus

#endif