# the name of the target operating system
SET(CMAKE_SYSTEM_NAME Windows)

# which compilers to use for C and C++
IF( NOT DEFINED MXE_DIR )
  message(FATAL_ERROR "Missing MXE_DIR")
ENDIF()
list(APPEND CMAKE_TRY_COMPILE_PLATFORM_VARIABLES "MXE_DIR")

SET(COMPILER_DIR "${MXE_DIR}/usr/bin")
SET(CMAKE_C_COMPILER   "${COMPILER_DIR}/i686-w64-mingw32.static-gcc")
SET(CMAKE_CXX_COMPILER "${COMPILER_DIR}/i686-w64-mingw32.static-g++")
SET(CMAKE_RC_COMPILER  "${COMPILER_DIR}/i686-w64-mingw32.static-windres")
SET(CMAKE_MC_COMPILER  "${COMPILER_DIR}/i686-w64-mingw32.static-windmc")

# compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" CACHE STRING "c++ flags")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -std=c++11" CACHE STRING "c flags")


# here is the target environment located
SET(CMAKE_FIND_ROOT_PATH "${MXE_DIR}/usr/i686-w64-mingw32.static")

## Use static boost libraries for windows
set(Boost_USE_STATIC_LIBS ON)

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search 
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

