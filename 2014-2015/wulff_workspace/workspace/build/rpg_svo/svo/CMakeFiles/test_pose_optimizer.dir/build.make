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
CMAKE_SOURCE_DIR = /home/cracker/workspace/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cracker/workspace/build

# Include any dependencies generated for this target.
include rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/depend.make

# Include the progress variables for this target.
include rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/progress.make

# Include the compile flags for this target's objects.
include rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/flags.make

rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o: rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/flags.make
rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o: /home/cracker/workspace/src/rpg_svo/svo/test/test_pose_optimizer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cracker/workspace/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o"
	cd /home/cracker/workspace/build/rpg_svo/svo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o -c /home/cracker/workspace/src/rpg_svo/svo/test/test_pose_optimizer.cpp

rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.i"
	cd /home/cracker/workspace/build/rpg_svo/svo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/cracker/workspace/src/rpg_svo/svo/test/test_pose_optimizer.cpp > CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.i

rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.s"
	cd /home/cracker/workspace/build/rpg_svo/svo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/cracker/workspace/src/rpg_svo/svo/test/test_pose_optimizer.cpp -o CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.s

rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o.requires:
.PHONY : rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o.requires

rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o.provides: rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o.requires
	$(MAKE) -f rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/build.make rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o.provides.build
.PHONY : rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o.provides

rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o.provides.build: rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o

# Object files for target test_pose_optimizer
test_pose_optimizer_OBJECTS = \
"CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o"

# External object files for target test_pose_optimizer
test_pose_optimizer_EXTERNAL_OBJECTS =

/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/build.make
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /home/cracker/workspace/devel/lib/libsvo.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /home/cracker/workspace/fast/build/libfast.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /opt/ros/indigo/lib/libroslib.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /home/cracker/workspace/devel/lib/libvikit_ros.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /opt/ros/indigo/lib/libtf.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /opt/ros/indigo/lib/libtf2_ros.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /opt/ros/indigo/lib/libactionlib.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /home/cracker/workspace/devel/lib/libmessage_filters.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /opt/ros/indigo/lib/libtf2.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /home/cracker/workspace/devel/lib/libvikit_common.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /home/cracker/workspace/Sophus/build/libSophus.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /home/cracker/workspace/devel/lib/libroscpp.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /home/cracker/workspace/devel/lib/librosconsole.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /home/cracker/workspace/devel/lib/librosconsole_log4cxx.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /home/cracker/workspace/devel/lib/librosconsole_backend_interface.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/liblog4cxx.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /opt/ros/indigo/lib/librostime.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /home/cracker/workspace/devel/lib/libxmlrpcpp.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /opt/ros/indigo/lib/libcpp_common.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/cracker/workspace/devel/lib/svo/test_pose_optimizer: rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/cracker/workspace/devel/lib/svo/test_pose_optimizer"
	cd /home/cracker/workspace/build/rpg_svo/svo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_pose_optimizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/build: /home/cracker/workspace/devel/lib/svo/test_pose_optimizer
.PHONY : rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/build

rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/requires: rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/test/test_pose_optimizer.cpp.o.requires
.PHONY : rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/requires

rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/clean:
	cd /home/cracker/workspace/build/rpg_svo/svo && $(CMAKE_COMMAND) -P CMakeFiles/test_pose_optimizer.dir/cmake_clean.cmake
.PHONY : rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/clean

rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/depend:
	cd /home/cracker/workspace/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cracker/workspace/src /home/cracker/workspace/src/rpg_svo/svo /home/cracker/workspace/build /home/cracker/workspace/build/rpg_svo/svo /home/cracker/workspace/build/rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rpg_svo/svo/CMakeFiles/test_pose_optimizer.dir/depend

