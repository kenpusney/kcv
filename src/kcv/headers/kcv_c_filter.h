
#ifndef __KCV_C_FILTER_H
#define __KCV_C_FILTER_H

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

typedef struct kcv_filter_t {
    int radius;
    double *data;
} kcv_filter_t;

#ifdef __cplusplus
}  // extern "C"
#endif // __cplusplus

#endif