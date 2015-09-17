# CMake generated Testfile for 
# Source directory: /home/cracker/workspace/src/vision_opencv/cv_bridge/test
# Build directory: /home/cracker/workspace/build/vision_opencv/cv_bridge/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(_ctest_cv_bridge_gtest_cv_bridge-utest "/home/cracker/workspace/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/cracker/workspace/build/test_results/cv_bridge/gtest-cv_bridge-utest.xml" "--return-code" "/home/cracker/workspace/devel/lib/cv_bridge/cv_bridge-utest --gtest_output=xml:/home/cracker/workspace/build/test_results/cv_bridge/gtest-cv_bridge-utest.xml")
ADD_TEST(_ctest_cv_bridge_nosetests_enumerants.py "/home/cracker/workspace/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/indigo/share/catkin/cmake/test/run_tests.py" "/home/cracker/workspace/build/test_results/cv_bridge/nosetests-enumerants.py.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/cracker/workspace/build/test_results/cv_bridge" "/usr/bin/nosetests-2.7 -P --process-timeout=60 /home/cracker/workspace/src/vision_opencv/cv_bridge/test/enumerants.py --with-xunit --xunit-file=/home/cracker/workspace/build/test_results/cv_bridge/nosetests-enumerants.py.xml")
