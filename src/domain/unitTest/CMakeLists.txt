SET(SOURCES
  UnitTest.cpp
  ../nina/PdfCreator.t.cpp
  ../nina/Archiver.t.cpp
  )
add_executable(unitTest ${SOURCES})
target_include_directories(unitTest
  PRIVATE ..
  )
target_link_libraries(unitTest
  nina_domain
  )

