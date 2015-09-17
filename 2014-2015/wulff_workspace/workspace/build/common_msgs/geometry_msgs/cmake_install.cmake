# Install script for directory: /home/cracker/workspace/src/common_msgs/geometry_msgs

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/cracker/workspace/install")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/geometry_msgs/msg" TYPE FILE FILES
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Point32.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PointStamped.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Polygon.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PolygonStamped.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose2D.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Pose.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseArray.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseStamped.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovariance.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/PoseWithCovarianceStamped.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Quaternion.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/QuaternionStamped.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Transform.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/TransformStamped.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Twist.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/TwistStamped.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/TwistWithCovariance.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/TwistWithCovarianceStamped.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Vector3Stamped.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/Wrench.msg"
    "/home/cracker/workspace/src/common_msgs/geometry_msgs/msg/WrenchStamped.msg"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/geometry_msgs/cmake" TYPE FILE FILES "/home/cracker/workspace/build/common_msgs/geometry_msgs/catkin_generated/installspace/geometry_msgs-msg-paths.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/cracker/workspace/devel/include/geometry_msgs")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/cracker/workspace/devel/share/common-lisp/ros/geometry_msgs")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/cracker/workspace/devel/lib/python2.7/dist-packages/geometry_msgs")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/cracker/workspace/devel/lib/python2.7/dist-packages/geometry_msgs")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/cracker/workspace/build/common_msgs/geometry_msgs/catkin_generated/installspace/geometry_msgs.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/geometry_msgs/cmake" TYPE FILE FILES "/home/cracker/workspace/build/common_msgs/geometry_msgs/catkin_generated/installspace/geometry_msgs-msg-extras.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/geometry_msgs/cmake" TYPE FILE FILES
    "/home/cracker/workspace/build/common_msgs/geometry_msgs/catkin_generated/installspace/geometry_msgsConfig.cmake"
    "/home/cracker/workspace/build/common_msgs/geometry_msgs/catkin_generated/installspace/geometry_msgsConfig-version.cmake"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/geometry_msgs" TYPE FILE FILES "/home/cracker/workspace/src/common_msgs/geometry_msgs/package.xml")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

