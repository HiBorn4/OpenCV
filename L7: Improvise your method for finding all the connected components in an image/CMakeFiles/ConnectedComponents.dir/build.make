# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image"

# Include any dependencies generated for this target.
include CMakeFiles/ConnectedComponents.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ConnectedComponents.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ConnectedComponents.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ConnectedComponents.dir/flags.make

CMakeFiles/ConnectedComponents.dir/connected_components.cpp.o: CMakeFiles/ConnectedComponents.dir/flags.make
CMakeFiles/ConnectedComponents.dir/connected_components.cpp.o: connected_components.cpp
CMakeFiles/ConnectedComponents.dir/connected_components.cpp.o: CMakeFiles/ConnectedComponents.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ConnectedComponents.dir/connected_components.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ConnectedComponents.dir/connected_components.cpp.o -MF CMakeFiles/ConnectedComponents.dir/connected_components.cpp.o.d -o CMakeFiles/ConnectedComponents.dir/connected_components.cpp.o -c "/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/connected_components.cpp"

CMakeFiles/ConnectedComponents.dir/connected_components.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ConnectedComponents.dir/connected_components.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/connected_components.cpp" > CMakeFiles/ConnectedComponents.dir/connected_components.cpp.i

CMakeFiles/ConnectedComponents.dir/connected_components.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ConnectedComponents.dir/connected_components.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/connected_components.cpp" -o CMakeFiles/ConnectedComponents.dir/connected_components.cpp.s

# Object files for target ConnectedComponents
ConnectedComponents_OBJECTS = \
"CMakeFiles/ConnectedComponents.dir/connected_components.cpp.o"

# External object files for target ConnectedComponents
ConnectedComponents_EXTERNAL_OBJECTS =

ConnectedComponents: CMakeFiles/ConnectedComponents.dir/connected_components.cpp.o
ConnectedComponents: CMakeFiles/ConnectedComponents.dir/build.make
ConnectedComponents: /usr/local/lib/libopencv_gapi.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_highgui.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_ml.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_objdetect.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_photo.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_stitching.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_video.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_videoio.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_imgcodecs.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_dnn.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_calib3d.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_features2d.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_flann.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_imgproc.so.4.9.0
ConnectedComponents: /usr/local/lib/libopencv_core.so.4.9.0
ConnectedComponents: CMakeFiles/ConnectedComponents.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ConnectedComponents"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ConnectedComponents.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ConnectedComponents.dir/build: ConnectedComponents
.PHONY : CMakeFiles/ConnectedComponents.dir/build

CMakeFiles/ConnectedComponents.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ConnectedComponents.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ConnectedComponents.dir/clean

CMakeFiles/ConnectedComponents.dir/depend:
	cd "/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image" "/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image" "/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image" "/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image" "/home/hi-born4/6th Sem/Image Processing and Computer Vision/L7: Improvise your method for finding all the connected components in an image/CMakeFiles/ConnectedComponents.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ConnectedComponents.dir/depend

