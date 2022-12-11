if(NOT DEFINED CMGym_DIR)
   set(CMGym_DIR "${CMAKE_CURRENT_LIST_DIR}/../CMakeGym" CACHE STRING "The top directory of CMGym")
endif()

include(${CMGym_DIR}/scripts/core.cmake)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/WSTRCore")