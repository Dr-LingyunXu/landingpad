# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "svo_msgs: 4 messages, 0 services")

set(MSG_I_FLAGS "-Isvo_msgs:/home/cracker/workspace/src/rpg_svo/svo_msgs/msg;-Igeometry_msgs:/home/cracker/workspace/src/common_msgs/geometry_msgs/msg;-Isensor_msgs:/home/cracker/workspace/src/common_msgs/sensor_msgs/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(svo_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/DenseInput.msg" NAME_WE)
add_custom_target(_svo_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "svo_msgs" "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/DenseInput.msg" "geometry_msgs/Point:sensor_msgs/Image:std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/NbvTrajectory.msg" NAME_WE)
add_custom_target(_svo_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "svo_msgs" "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/NbvTrajectory.msg" "geometry_msgs/Point:std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Feature.msg" NAME_WE)
add_custom_target(_svo_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "svo_msgs" "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Feature.msg" ""
)

get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Info.msg" NAME_WE)
add_custom_target(_svo_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "svo_msgs" "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Info.msg" "std_msgs/Header"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/DenseInput.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/home/cracker/workspace/src/common_msgs/sensor_msgs/msg/Image.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svo_msgs
)
_generate_msg_cpp(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/NbvTrajectory.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svo_msgs
)
_generate_msg_cpp(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Feature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svo_msgs
)
_generate_msg_cpp(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Info.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svo_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(svo_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svo_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(svo_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(svo_msgs_generate_messages svo_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/DenseInput.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_cpp _svo_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/NbvTrajectory.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_cpp _svo_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Feature.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_cpp _svo_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Info.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_cpp _svo_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(svo_msgs_gencpp)
add_dependencies(svo_msgs_gencpp svo_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS svo_msgs_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/DenseInput.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/home/cracker/workspace/src/common_msgs/sensor_msgs/msg/Image.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svo_msgs
)
_generate_msg_lisp(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/NbvTrajectory.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svo_msgs
)
_generate_msg_lisp(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Feature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svo_msgs
)
_generate_msg_lisp(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Info.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svo_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(svo_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svo_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(svo_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(svo_msgs_generate_messages svo_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/DenseInput.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_lisp _svo_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/NbvTrajectory.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_lisp _svo_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Feature.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_lisp _svo_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Info.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_lisp _svo_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(svo_msgs_genlisp)
add_dependencies(svo_msgs_genlisp svo_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS svo_msgs_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/DenseInput.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/home/cracker/workspace/src/common_msgs/sensor_msgs/msg/Image.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svo_msgs
)
_generate_msg_py(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/NbvTrajectory.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svo_msgs
)
_generate_msg_py(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Feature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svo_msgs
)
_generate_msg_py(svo_msgs
  "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Info.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svo_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(svo_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svo_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(svo_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(svo_msgs_generate_messages svo_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/DenseInput.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_py _svo_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/NbvTrajectory.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_py _svo_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Feature.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_py _svo_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/rpg_svo/svo_msgs/msg/Info.msg" NAME_WE)
add_dependencies(svo_msgs_generate_messages_py _svo_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(svo_msgs_genpy)
add_dependencies(svo_msgs_genpy svo_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS svo_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svo_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/svo_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(svo_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
add_dependencies(svo_msgs_generate_messages_cpp sensor_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svo_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/svo_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(svo_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
add_dependencies(svo_msgs_generate_messages_lisp sensor_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svo_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svo_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/svo_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(svo_msgs_generate_messages_py geometry_msgs_generate_messages_py)
add_dependencies(svo_msgs_generate_messages_py sensor_msgs_generate_messages_py)
