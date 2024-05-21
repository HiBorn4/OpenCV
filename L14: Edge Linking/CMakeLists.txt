cmake_minimum_required(VERSION 3.5)
project(EL)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(EL edge_linking.cpp)

# Link OpenCV libraries
target_link_libraries(EL ${OpenCV_LIBS})