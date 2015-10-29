
#include <kcv_c.h>

int kcvFreeImage(kcv_image_t* img) {
    if(img->data != nullptr) {
        delete[] img->data;
        img->data = nullptr;
    }
}