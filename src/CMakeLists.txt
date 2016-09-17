cmake_minimum_required (VERSION 3.1)

project(kcv)
add_subdirectory(kcv)
add_subdirectory(utils)

include_directories(kcv/include)
include_directories(utils)

add_executable(kcv_main main)
set_property(TARGET kcv_main PROPERTY CXX_STANDARD 14)

target_link_libraries(kcv_main kcv utils fltk fltk_images png jpeg z pthread)