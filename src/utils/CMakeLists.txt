set(UTILS_LIB_SRC
    utils.cpp
)

include_directories(../kcv/include)

add_library(utils ${UTILS_LIB_SRC})
set_property(TARGET utils PROPERTY CXX_STANDARD 14)
