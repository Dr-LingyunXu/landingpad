# CMake generated Testfile for 
# Source directory: /home/cracker/workspace/src/ros_comm/test/test_rosparam
# Build directory: /home/cracker/workspace/build/ros_comm/test/test_rosparam
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(_ctest_test_rosparam_rostest_test_rosparam.test "/home/cracker/workspace/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/cracker/workspace/build/test_results/test_rosparam/rostest-test_rosparam.xml" "--return-code" "/home/cracker/workspace/src/ros_comm/tools/rostest/scripts/rostest --pkgdir=/home/cracker/workspace/src/ros_comm/test/test_rosparam --package=test_rosparam --results-filename test_rosparam.xml /home/cracker/workspace/src/ros_comm/test/test_rosparam/test/rosparam.test ")
ADD_TEST(_ctest_test_rosparam_nosetests_test "/home/cracker/workspace/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/cracker/workspace/build/test_results/test_rosparam/nosetests-test.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/cracker/workspace/build/test_results/test_rosparam" "/usr/bin/nosetests-2.7 -P --process-timeout=60 --where=/home/cracker/workspace/src/ros_comm/test/test_rosparam/test --with-xunit --xunit-file=/home/cracker/workspace/build/test_results/test_rosparam/nosetests-test.xml")
