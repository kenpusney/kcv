set(KCV_LIB_SRC
    kcvFilter.cpp
    kcvImage.cpp
    kcvTransformer.cpp
)

include_directories(include)

add_library(kcv ${KCV_LIB_SRC})
set_property(TARGET kcv PROPERTY CXX_STANDARD 14)
