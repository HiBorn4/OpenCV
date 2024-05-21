cmake_minimum_required(VERSION 3.5)
project(RegionSeg)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(RegionSeg region_seg.cpp)

# Link OpenCV libraries
target_link_libraries(RegionSeg ${OpenCV_LIBS})