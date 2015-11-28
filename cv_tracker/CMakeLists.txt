cmake_minimum_required(VERSION 2.8.3)
list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
project(cv_tracker)



find_package( OpenCV REQUIRED )
add_library( LED src/LED.cpp )
add_library( Coord src/Coord.cpp )
add_library( Triangle src/Triangle.cpp )
add_library( Camera src/Camera.cpp )
add_executable( tracker src/tracker.cpp )
add_executable( calibrate src/calibrate.cpp )
add_executable( threshold src/threshold.cpp )

target_link_libraries( tracker ${OpenCV_LIBS} ${catkin_LIBRARIES} LED Coord Triangle Camera )
target_link_libraries( calibrate ${OpenCV_LIBS} ${catkin_LIBRARIES} )
target_link_libraries( threshold ${OpenCV_LIBS} ${catkin_LIBRARIES} )
