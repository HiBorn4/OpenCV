cmake_minimum_required(VERSION 3.5)
project(RegionSegmentation)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(RegionSegmentation region_segmentation.cpp)

# Link OpenCV libraries
target_link_libraries(RegionSegmentation ${OpenCV_LIBS})