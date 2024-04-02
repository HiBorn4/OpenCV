cmake_minimum_required(VERSION 3.5)
project(HistogramEqualization)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(HistogramEqualization histogram_equalization_greyscale_image.cpp)

# Link OpenCV libraries
target_link_libraries(HistogramEqualization ${OpenCV_LIBS})