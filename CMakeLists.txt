project(acranoid)
cmake_minimum_required(VERSION 3.10)

find_package(Doxygen REQUIRED)

# Add the cmake folder so the FindSphinx module is found
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_subdirectory(libs)
add_subdirectory(src)
add_subdirectory (docs)