cmake_minimum_required (VERSION 3.0.0)

find_package(Boost COMPONENTS unit_test_framework filesystem)
include_directories(
  .
  ${Boost_INCLUDE_DIR}
  )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_subdirectory(nina)
add_subdirectory(unitTest)


