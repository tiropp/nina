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
