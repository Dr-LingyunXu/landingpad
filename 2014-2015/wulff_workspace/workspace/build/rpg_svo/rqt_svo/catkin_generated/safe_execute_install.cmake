execute_process(COMMAND "/home/cracker/workspace/build/rpg_svo/rqt_svo/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/cracker/workspace/build/rpg_svo/rqt_svo/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
