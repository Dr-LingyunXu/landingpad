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
include openni_camera/CMakeFiles/openni_node.dir/depend.make

# Include the progress variables for this target.
include openni_camera/CMakeFiles/openni_node.dir/progress.make

# Include the compile flags for this target's objects.
include openni_camera/CMakeFiles/openni_node.dir/flags.make

openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o: openni_camera/CMakeFiles/openni_node.dir/flags.make
openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o: /home/cracker/workspace/src/openni_camera/src/nodes/openni_node.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cracker/workspace/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o"
	cd /home/cracker/workspace/build/openni_camera && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o -c /home/cracker/workspace/src/openni_camera/src/nodes/openni_node.cpp

openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.i"
	cd /home/cracker/workspace/build/openni_camera && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/cracker/workspace/src/openni_camera/src/nodes/openni_node.cpp > CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.i

openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.s"
	cd /home/cracker/workspace/build/openni_camera && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/cracker/workspace/src/openni_camera/src/nodes/openni_node.cpp -o CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.s

openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o.requires:
.PHONY : openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o.requires

openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o.provides: openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o.requires
	$(MAKE) -f openni_camera/CMakeFiles/openni_node.dir/build.make openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o.provides.build
.PHONY : openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o.provides

openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o.provides.build: openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o

# Object files for target openni_node
openni_node_OBJECTS = \
"CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o"

# External object files for target openni_node
openni_node_EXTERNAL_OBJECTS =

/home/cracker/workspace/devel/lib/openni_camera/openni_node: openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o
/home/cracker/workspace/devel/lib/openni_camera/openni_node: openni_camera/CMakeFiles/openni_node.dir/build.make
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /home/cracker/workspace/devel/lib/libopenni_driver.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /opt/ros/indigo/lib/libcamera_info_manager.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /opt/ros/indigo/lib/libdynamic_reconfigure_config_init_mutex.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /opt/ros/indigo/lib/libimage_transport.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /home/cracker/workspace/devel/lib/libmessage_filters.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /opt/ros/indigo/lib/libnodeletlib.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /opt/ros/indigo/lib/libbondcpp.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libuuid.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libtinyxml.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /opt/ros/indigo/lib/libclass_loader.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/libPocoFoundation.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libdl.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /opt/ros/indigo/lib/libroslib.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /home/cracker/workspace/devel/lib/libroscpp.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /home/cracker/workspace/devel/lib/librosconsole.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /home/cracker/workspace/devel/lib/librosconsole_log4cxx.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /home/cracker/workspace/devel/lib/librosconsole_backend_interface.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/liblog4cxx.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /home/cracker/workspace/devel/lib/libxmlrpcpp.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /opt/ros/indigo/lib/librostime.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /opt/ros/indigo/lib/libcpp_common.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/cracker/workspace/devel/lib/openni_camera/openni_node: openni_camera/CMakeFiles/openni_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/cracker/workspace/devel/lib/openni_camera/openni_node"
	cd /home/cracker/workspace/build/openni_camera && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openni_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
openni_camera/CMakeFiles/openni_node.dir/build: /home/cracker/workspace/devel/lib/openni_camera/openni_node
.PHONY : openni_camera/CMakeFiles/openni_node.dir/build

openni_camera/CMakeFiles/openni_node.dir/requires: openni_camera/CMakeFiles/openni_node.dir/src/nodes/openni_node.cpp.o.requires
.PHONY : openni_camera/CMakeFiles/openni_node.dir/requires

openni_camera/CMakeFiles/openni_node.dir/clean:
	cd /home/cracker/workspace/build/openni_camera && $(CMAKE_COMMAND) -P CMakeFiles/openni_node.dir/cmake_clean.cmake
.PHONY : openni_camera/CMakeFiles/openni_node.dir/clean

openni_camera/CMakeFiles/openni_node.dir/depend:
	cd /home/cracker/workspace/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cracker/workspace/src /home/cracker/workspace/src/openni_camera /home/cracker/workspace/build /home/cracker/workspace/build/openni_camera /home/cracker/workspace/build/openni_camera/CMakeFiles/openni_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : openni_camera/CMakeFiles/openni_node.dir/depend

