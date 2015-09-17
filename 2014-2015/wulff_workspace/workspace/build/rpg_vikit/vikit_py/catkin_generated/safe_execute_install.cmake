execute_process(COMMAND "/home/cracker/workspace/build/rpg_vikit/vikit_py/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/cracker/workspace/build/rpg_vikit/vikit_py/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
