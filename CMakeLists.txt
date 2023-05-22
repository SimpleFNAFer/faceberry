cmake_minimum_required(VERSION 3.25)
project(faceberry)

set(CMAKE_CXX_STANDARD 17)

add_executable(faceberry main.cpp opencv-functions.h)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(faceberry ${OpenCV_LIBS})
