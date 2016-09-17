set(TEST_LIB_SRC
    testTransformer.cpp
)

include_directories(../kcv/include)
add_library(kcv_test ${TEST_LIB_SRC})
set_property(TARGET kcv_test PROPERTY CXX_STANDARD 14)
