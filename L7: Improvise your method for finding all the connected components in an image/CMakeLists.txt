cmake_minimum_required(VERSION 3.5)
project(ConnectedComponents)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(ConnectedComponents connected_components.cpp)

# Link OpenCV libraries
target_link_libraries(ConnectedComponents ${OpenCV_LIBS})