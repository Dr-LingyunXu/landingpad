# CMake generated Testfile for 
# Source directory: /home/cracker/workspace/src/vision_opencv/image_geometry/test
# Build directory: /home/cracker/workspace/build/vision_opencv/image_geometry/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(_ctest_image_geometry_nosetests_directed.py "/home/cracker/workspace/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/cracker/workspace/build/test_results/image_geometry/nosetests-directed.py.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/cracker/workspace/build/test_results/image_geometry" "/usr/bin/nosetests-2.7 -P --process-timeout=60 /home/cracker/workspace/src/vision_opencv/image_geometry/test/directed.py --with-xunit --xunit-file=/home/cracker/workspace/build/test_results/image_geometry/nosetests-directed.py.xml")
ADD_TEST(_ctest_image_geometry_gtest_image_geometry-utest "/home/cracker/workspace/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/cracker/workspace/build/test_results/image_geometry/gtest-image_geometry-utest.xml" "--return-code" "/home/cracker/workspace/devel/lib/image_geometry/image_geometry-utest --gtest_output=xml:/home/cracker/workspace/build/test_results/image_geometry/gtest-image_geometry-utest.xml")
