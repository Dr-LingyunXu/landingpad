# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/julian/workspace/landingpad/qr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julian/workspace/landingpad/qr

# Include any dependencies generated for this target.
include CMakeFiles/qr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/qr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qr.dir/flags.make

CMakeFiles/qr.dir/qr.cpp.o: CMakeFiles/qr.dir/flags.make
CMakeFiles/qr.dir/qr.cpp.o: qr.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/julian/workspace/landingpad/qr/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/qr.dir/qr.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/qr.dir/qr.cpp.o -c /home/julian/workspace/landingpad/qr/qr.cpp

CMakeFiles/qr.dir/qr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qr.dir/qr.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/julian/workspace/landingpad/qr/qr.cpp > CMakeFiles/qr.dir/qr.cpp.i

CMakeFiles/qr.dir/qr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qr.dir/qr.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/julian/workspace/landingpad/qr/qr.cpp -o CMakeFiles/qr.dir/qr.cpp.s

CMakeFiles/qr.dir/qr.cpp.o.requires:
.PHONY : CMakeFiles/qr.dir/qr.cpp.o.requires

CMakeFiles/qr.dir/qr.cpp.o.provides: CMakeFiles/qr.dir/qr.cpp.o.requires
	$(MAKE) -f CMakeFiles/qr.dir/build.make CMakeFiles/qr.dir/qr.cpp.o.provides.build
.PHONY : CMakeFiles/qr.dir/qr.cpp.o.provides

CMakeFiles/qr.dir/qr.cpp.o.provides.build: CMakeFiles/qr.dir/qr.cpp.o

# Object files for target qr
qr_OBJECTS = \
"CMakeFiles/qr.dir/qr.cpp.o"

# External object files for target qr
qr_EXTERNAL_OBJECTS =

qr: CMakeFiles/qr.dir/qr.cpp.o
qr: CMakeFiles/qr.dir/build.make
qr: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
qr: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
qr: CMakeFiles/qr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable qr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qr.dir/build: qr
.PHONY : CMakeFiles/qr.dir/build

CMakeFiles/qr.dir/requires: CMakeFiles/qr.dir/qr.cpp.o.requires
.PHONY : CMakeFiles/qr.dir/requires

CMakeFiles/qr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/qr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/qr.dir/clean

CMakeFiles/qr.dir/depend:
	cd /home/julian/workspace/landingpad/qr && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julian/workspace/landingpad/qr /home/julian/workspace/landingpad/qr /home/julian/workspace/landingpad/qr /home/julian/workspace/landingpad/qr /home/julian/workspace/landingpad/qr/CMakeFiles/qr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qr.dir/depend

