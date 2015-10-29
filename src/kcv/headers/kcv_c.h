
#ifndef __KCV_C_H
#define __KCV_C_H

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

typedef struct kcv_point_t
{
    int x;
    int y;
} kyc_point_t;

typedef struct kcv_vec2d_t
{
    kyc_point_t from;
    kyc_point_t to;
} kyc_vec2d_t;

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
} kyc_color_t;

int kcvFreeImage(kcv_image_t* img);

kcv_color_t kcvGetPixel(kcv_image_t* img, int x, int y);

void kcvSetPixel(kcv_image_t* img, kcv_color_t color, int x, int y);

#ifdef __cplusplus
}  // extern "C"
#endif // __cplusplus

#endif