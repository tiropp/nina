SET(SOURCES
  Bank.cpp
  Date.cpp  
  PdfCreator.cpp
  Position.cpp
  PositionContainer.cpp
  Archiver.cpp
  Vat.cpp
  BottomField.cpp
  Money.cpp
  )
add_library(nina_domain ${SOURCES})
target_include_directories(nina_domain
  PUBLIC ".."
  )
target_link_libraries(nina_domain ${Boost_LIBRARIES})
