# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ptam_com: 6 messages, 2 services")

set(MSG_I_FLAGS "-Iptam_com:/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Igeometry_msgs:/home/cracker/workspace/src/common_msgs/geometry_msgs/msg;-Isensor_msgs:/home/cracker/workspace/src/common_msgs/sensor_msgs/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(ptam_com_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/PointCloud.srv" NAME_WE)
add_custom_target(_ptam_com_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ptam_com" "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/PointCloud.srv" "sensor_msgs/PointField:sensor_msgs/PointCloud2:std_msgs/Header"
)

get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/KeyFrame_srv.srv" NAME_WE)
add_custom_target(_ptam_com_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ptam_com" "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/KeyFrame_srv.srv" "geometry_msgs/Point:geometry_msgs/Quaternion:std_msgs/Header:geometry_msgs/PoseWithCovarianceStamped:geometry_msgs/Pose:geometry_msgs/PoseWithCovariance"
)

get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/KeyFrame_msg.msg" NAME_WE)
add_custom_target(_ptam_com_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ptam_com" "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/KeyFrame_msg.msg" "geometry_msgs/Point:geometry_msgs/Quaternion:std_msgs/Header:geometry_msgs/PoseWithCovarianceStamped:geometry_msgs/Pose:geometry_msgs/PoseWithCovariance"
)

get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/Vector3Array.msg" NAME_WE)
add_custom_target(_ptam_com_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ptam_com" "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/Vector3Array.msg" "geometry_msgs/Vector3:std_msgs/Header"
)

get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapScan.msg" NAME_WE)
add_custom_target(_ptam_com_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ptam_com" "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapScan.msg" "geometry_msgs/Vector3:geometry_msgs/Quaternion:ptam_com/OctoMapPointStamped:geometry_msgs/Point:std_msgs/Header:geometry_msgs/PoseWithCovarianceStamped:geometry_msgs/Pose:ptam_com/OctoMapPointArray:geometry_msgs/PoseWithCovariance"
)

get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/ptam_info.msg" NAME_WE)
add_custom_target(_ptam_com_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ptam_com" "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/ptam_info.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg" NAME_WE)
add_custom_target(_ptam_com_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ptam_com" "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg" "geometry_msgs/Vector3:std_msgs/Header"
)

get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointArray.msg" NAME_WE)
add_custom_target(_ptam_com_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ptam_com" "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointArray.msg" "ptam_com/OctoMapPointStamped:geometry_msgs/Vector3:std_msgs/Header"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/KeyFrame_msg.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovarianceStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovariance.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ptam_com
)
_generate_msg_cpp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/Vector3Array.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ptam_com
)
_generate_msg_cpp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapScan.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovarianceStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointArray.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovariance.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ptam_com
)
_generate_msg_cpp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/ptam_info.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ptam_com
)
_generate_msg_cpp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ptam_com
)
_generate_msg_cpp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointArray.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ptam_com
)

### Generating Services
_generate_srv_cpp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/PointCloud.srv"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/sensor_msgs/msg/PointField.msg;/home/cracker/workspace/src/common_msgs/sensor_msgs/msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ptam_com
)
_generate_srv_cpp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/KeyFrame_srv.srv"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovarianceStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovariance.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ptam_com
)

### Generating Module File
_generate_module_cpp(ptam_com
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ptam_com
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ptam_com_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(ptam_com_generate_messages ptam_com_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/PointCloud.srv" NAME_WE)
add_dependencies(ptam_com_generate_messages_cpp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/KeyFrame_srv.srv" NAME_WE)
add_dependencies(ptam_com_generate_messages_cpp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/KeyFrame_msg.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_cpp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/Vector3Array.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_cpp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapScan.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_cpp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/ptam_info.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_cpp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_cpp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointArray.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_cpp _ptam_com_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ptam_com_gencpp)
add_dependencies(ptam_com_gencpp ptam_com_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ptam_com_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/KeyFrame_msg.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovarianceStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovariance.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ptam_com
)
_generate_msg_lisp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/Vector3Array.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ptam_com
)
_generate_msg_lisp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapScan.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovarianceStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointArray.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovariance.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ptam_com
)
_generate_msg_lisp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/ptam_info.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ptam_com
)
_generate_msg_lisp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ptam_com
)
_generate_msg_lisp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointArray.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ptam_com
)

### Generating Services
_generate_srv_lisp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/PointCloud.srv"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/sensor_msgs/msg/PointField.msg;/home/cracker/workspace/src/common_msgs/sensor_msgs/msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ptam_com
)
_generate_srv_lisp(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/KeyFrame_srv.srv"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovarianceStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovariance.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ptam_com
)

### Generating Module File
_generate_module_lisp(ptam_com
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ptam_com
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(ptam_com_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(ptam_com_generate_messages ptam_com_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/PointCloud.srv" NAME_WE)
add_dependencies(ptam_com_generate_messages_lisp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/KeyFrame_srv.srv" NAME_WE)
add_dependencies(ptam_com_generate_messages_lisp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/KeyFrame_msg.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_lisp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/Vector3Array.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_lisp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapScan.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_lisp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/ptam_info.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_lisp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_lisp _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointArray.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_lisp _ptam_com_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ptam_com_genlisp)
add_dependencies(ptam_com_genlisp ptam_com_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ptam_com_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/KeyFrame_msg.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovarianceStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovariance.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com
)
_generate_msg_py(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/Vector3Array.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com
)
_generate_msg_py(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapScan.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovarianceStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointArray.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovariance.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com
)
_generate_msg_py(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/ptam_info.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com
)
_generate_msg_py(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com
)
_generate_msg_py(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointArray.msg"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com
)

### Generating Services
_generate_srv_py(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/PointCloud.srv"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/sensor_msgs/msg/PointField.msg;/home/cracker/workspace/src/common_msgs/sensor_msgs/msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com
)
_generate_srv_py(ptam_com
  "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/KeyFrame_srv.srv"
  "${MSG_I_FLAGS}"
  "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovarianceStamped.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg;/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovariance.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com
)

### Generating Module File
_generate_module_py(ptam_com
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ptam_com_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(ptam_com_generate_messages ptam_com_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/PointCloud.srv" NAME_WE)
add_dependencies(ptam_com_generate_messages_py _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/KeyFrame_srv.srv" NAME_WE)
add_dependencies(ptam_com_generate_messages_py _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/KeyFrame_msg.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_py _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/Vector3Array.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_py _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapScan.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_py _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/ptam_info.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_py _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointStamped.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_py _ptam_com_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cracker/workspace/src/ethzasl_ptam/ptam_com/msg/OctoMapPointArray.msg" NAME_WE)
add_dependencies(ptam_com_generate_messages_py _ptam_com_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ptam_com_genpy)
add_dependencies(ptam_com_genpy ptam_com_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ptam_com_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ptam_com)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ptam_com
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(ptam_com_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(ptam_com_generate_messages_cpp geometry_msgs_generate_messages_cpp)
add_dependencies(ptam_com_generate_messages_cpp sensor_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ptam_com)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ptam_com
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(ptam_com_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(ptam_com_generate_messages_lisp geometry_msgs_generate_messages_lisp)
add_dependencies(ptam_com_generate_messages_lisp sensor_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ptam_com
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(ptam_com_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(ptam_com_generate_messages_py geometry_msgs_generate_messages_py)
add_dependencies(ptam_com_generate_messages_py sensor_msgs_generate_messages_py)
