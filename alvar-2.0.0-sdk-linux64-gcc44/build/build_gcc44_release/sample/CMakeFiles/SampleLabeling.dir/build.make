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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/build/build_gcc44_release

# Include any dependencies generated for this target.
include sample/CMakeFiles/SampleLabeling.dir/depend.make

# Include the progress variables for this target.
include sample/CMakeFiles/SampleLabeling.dir/progress.make

# Include the compile flags for this target's objects.
include sample/CMakeFiles/SampleLabeling.dir/flags.make

sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o: sample/CMakeFiles/SampleLabeling.dir/flags.make
sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o: ../../sample/SampleLabeling.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/build/build_gcc44_release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o"
	cd /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/build/build_gcc44_release/sample && /usr/bin/g++-4.4   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o -c /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/sample/SampleLabeling.cpp

sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.i"
	cd /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/build/build_gcc44_release/sample && /usr/bin/g++-4.4  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/sample/SampleLabeling.cpp > CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.i

sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.s"
	cd /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/build/build_gcc44_release/sample && /usr/bin/g++-4.4  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/sample/SampleLabeling.cpp -o CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.s

sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o.requires:
.PHONY : sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o.requires

sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o.provides: sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o.requires
	$(MAKE) -f sample/CMakeFiles/SampleLabeling.dir/build.make sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o.provides.build
.PHONY : sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o.provides

sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o.provides.build: sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o

# Object files for target SampleLabeling
SampleLabeling_OBJECTS = \
"CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o"

# External object files for target SampleLabeling
SampleLabeling_EXTERNAL_OBJECTS =

sample/samplelabeling: sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o
sample/samplelabeling: sample/CMakeFiles/SampleLabeling.dir/build.make
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
sample/samplelabeling: ../../bin/libalvar200.so
sample/samplelabeling: ../../bin/libalvarplatform200.so
sample/samplelabeling: sample/libSharedSamples.a
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
sample/samplelabeling: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
sample/samplelabeling: sample/CMakeFiles/SampleLabeling.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable samplelabeling"
	cd /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/build/build_gcc44_release/sample && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SampleLabeling.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sample/CMakeFiles/SampleLabeling.dir/build: sample/samplelabeling
.PHONY : sample/CMakeFiles/SampleLabeling.dir/build

sample/CMakeFiles/SampleLabeling.dir/requires: sample/CMakeFiles/SampleLabeling.dir/SampleLabeling.cpp.o.requires
.PHONY : sample/CMakeFiles/SampleLabeling.dir/requires

sample/CMakeFiles/SampleLabeling.dir/clean:
	cd /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/build/build_gcc44_release/sample && $(CMAKE_COMMAND) -P CMakeFiles/SampleLabeling.dir/cmake_clean.cmake
.PHONY : sample/CMakeFiles/SampleLabeling.dir/clean

sample/CMakeFiles/SampleLabeling.dir/depend:
	cd /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/build/build_gcc44_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44 /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/sample /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/build/build_gcc44_release /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/build/build_gcc44_release/sample /home/drgeyer/Downloads/alvar-2.0.0-sdk-linux64-gcc44/build/build_gcc44_release/sample/CMakeFiles/SampleLabeling.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sample/CMakeFiles/SampleLabeling.dir/depend

