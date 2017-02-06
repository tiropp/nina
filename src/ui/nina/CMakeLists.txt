set(SOURCES
  main.cpp
  invoicemodel.cpp
  sendermodel.cpp
  positionmodel.cpp
  positioncontainermodel.cpp
  addressmodel.cpp
  receivermodel.cpp
  bankmodel.cpp
  settingsmodel.cpp
  datemodel.cpp
  filesavedialog.cpp
  filedialogbase.cpp
  fileopendialog.cpp
  vatmodel.cpp
  detail/conversion.cpp
  )
qt5_add_resources(RESOURCES qml.qrc)
add_executable(nina ${SOURCES} ${RESOURCES})
target_include_directories(nina
  PRIVATE ${CMAKE_SOURCE_DIR}/src/domain
  )
target_link_libraries(nina
    nina_domain
    Qt5::Qml
    Qt5::Widgets
    )
  
install(TARGETS nina
  DESTINATION bin
  )
