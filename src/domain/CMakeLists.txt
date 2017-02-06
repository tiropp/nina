add_subdirectory( nina )

## Somehow tests cannot link due to some unmet references to some boost
## libraries.
if( NOT WIN32 )
  add_subdirectory( unitTest )
endif()
