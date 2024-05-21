cmake_minimum_required(VERSION 3.5)
project(DilationErosion)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(DilationErosion dilation_erosion.cpp)

# Link OpenCV libraries
target_link_libraries(DilationErosion ${OpenCV_LIBS})