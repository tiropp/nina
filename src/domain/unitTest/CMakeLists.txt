SET(SOURCES
  UnitTest.cpp
  ../nina/PdfCreator.t.cpp
  )
include_directories(..)
add_executable(unitTest ${SOURCES})
target_link_libraries(unitTest
  ${Boost_LIBRARIES}
  nina_domain
  )

