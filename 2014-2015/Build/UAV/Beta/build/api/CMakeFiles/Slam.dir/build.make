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
CMAKE_SOURCE_DIR = /home/cracker/workspace/Build/UAV/Beta/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cracker/workspace/Build/UAV/Beta/build

# Include any dependencies generated for this target.
include api/CMakeFiles/Slam.dir/depend.make

# Include the progress variables for this target.
include api/CMakeFiles/Slam.dir/progress.make

# Include the compile flags for this target's objects.
include api/CMakeFiles/Slam.dir/flags.make

api/CMakeFiles/Slam.dir/src/Slams.C.o: api/CMakeFiles/Slam.dir/flags.make
api/CMakeFiles/Slam.dir/src/Slams.C.o: /home/cracker/workspace/Build/UAV/Beta/src/api/src/Slams.C
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cracker/workspace/Build/UAV/Beta/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object api/CMakeFiles/Slam.dir/src/Slams.C.o"
	cd /home/cracker/workspace/Build/UAV/Beta/build/api && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Slam.dir/src/Slams.C.o -c /home/cracker/workspace/Build/UAV/Beta/src/api/src/Slams.C

api/CMakeFiles/Slam.dir/src/Slams.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Slam.dir/src/Slams.C.i"
	cd /home/cracker/workspace/Build/UAV/Beta/build/api && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/cracker/workspace/Build/UAV/Beta/src/api/src/Slams.C > CMakeFiles/Slam.dir/src/Slams.C.i

api/CMakeFiles/Slam.dir/src/Slams.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Slam.dir/src/Slams.C.s"
	cd /home/cracker/workspace/Build/UAV/Beta/build/api && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/cracker/workspace/Build/UAV/Beta/src/api/src/Slams.C -o CMakeFiles/Slam.dir/src/Slams.C.s

api/CMakeFiles/Slam.dir/src/Slams.C.o.requires:
.PHONY : api/CMakeFiles/Slam.dir/src/Slams.C.o.requires

api/CMakeFiles/Slam.dir/src/Slams.C.o.provides: api/CMakeFiles/Slam.dir/src/Slams.C.o.requires
	$(MAKE) -f api/CMakeFiles/Slam.dir/build.make api/CMakeFiles/Slam.dir/src/Slams.C.o.provides.build
.PHONY : api/CMakeFiles/Slam.dir/src/Slams.C.o.provides

api/CMakeFiles/Slam.dir/src/Slams.C.o.provides.build: api/CMakeFiles/Slam.dir/src/Slams.C.o

# Object files for target Slam
Slam_OBJECTS = \
"CMakeFiles/Slam.dir/src/Slams.C.o"

# External object files for target Slam
Slam_EXTERNAL_OBJECTS =

/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: api/CMakeFiles/Slam.dir/src/Slams.C.o
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: api/CMakeFiles/Slam.dir/build.make
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /opt/ros/indigo/lib/libroscpp.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /opt/ros/indigo/lib/librosconsole.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /usr/lib/liblog4cxx.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /opt/ros/indigo/lib/librostime.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /opt/ros/indigo/lib/libcpp_common.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam: api/CMakeFiles/Slam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam"
	cd /home/cracker/workspace/Build/UAV/Beta/build/api && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Slam.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
api/CMakeFiles/Slam.dir/build: /home/cracker/workspace/Build/UAV/Beta/devel/lib/api/Slam
.PHONY : api/CMakeFiles/Slam.dir/build

api/CMakeFiles/Slam.dir/requires: api/CMakeFiles/Slam.dir/src/Slams.C.o.requires
.PHONY : api/CMakeFiles/Slam.dir/requires

api/CMakeFiles/Slam.dir/clean:
	cd /home/cracker/workspace/Build/UAV/Beta/build/api && $(CMAKE_COMMAND) -P CMakeFiles/Slam.dir/cmake_clean.cmake
.PHONY : api/CMakeFiles/Slam.dir/clean

api/CMakeFiles/Slam.dir/depend:
	cd /home/cracker/workspace/Build/UAV/Beta/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cracker/workspace/Build/UAV/Beta/src /home/cracker/workspace/Build/UAV/Beta/src/api /home/cracker/workspace/Build/UAV/Beta/build /home/cracker/workspace/Build/UAV/Beta/build/api /home/cracker/workspace/Build/UAV/Beta/build/api/CMakeFiles/Slam.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : api/CMakeFiles/Slam.dir/depend

