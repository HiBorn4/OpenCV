cmake_minimum_required(VERSION 3.5)
project(LOG)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(LOG edge_detection_LOG.cpp)

# Link OpenCV libraries
target_link_libraries(LOG ${OpenCV_LIBS})