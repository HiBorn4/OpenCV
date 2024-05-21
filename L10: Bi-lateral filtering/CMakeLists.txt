cmake_minimum_required(VERSION 3.5)
project(BilateralFiltering)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(BilateralFiltering bilateral_filtering.cpp)

# Link OpenCV libraries
target_link_libraries(BilateralFiltering ${OpenCV_LIBS})