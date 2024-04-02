cmake_minimum_required(VERSION 3.5)
project(HistogramMatching)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(HistogramMatching histogram_matching_pixels.cpp)

# Link OpenCV libraries
target_link_libraries(HistogramMatching ${OpenCV_LIBS})