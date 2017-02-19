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
  miscmodel.cpp
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

if( WIN32 )
  ## mwindows:
  ##   Make the application a UI app, i.e. no CMD shell is shown
  set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -mwindows")
endif()


##################
## INSTALLATION ##
##################
if( WIN32 )
  install(TARGETS nina
    DESTINATION .
    )
  
  ## Install Qt libraries
  get_property(qt5_core_dll TARGET Qt5::Core PROPERTY LOCATION)
  get_filename_component(qt5_bin_dir "${qt5_core_dll}" DIRECTORY)
  set(qt5_dir "${qt5_bin_dir}/..")
  
  install(FILES
    ${qt5_bin_dir}/Qt5Core.dll
    ${qt5_bin_dir}/Qt5Network.dll
    ${qt5_bin_dir}/Qt5Qml.dll
    ${qt5_bin_dir}/Qt5Gui.dll
    ${qt5_bin_dir}/Qt5Quick.dll
    ${qt5_bin_dir}/Qt5QuickControls2.dll
    ${qt5_bin_dir}/Qt5QuickTemplates2.dll
    ${qt5_bin_dir}/Qt5Svg.dll
    ${qt5_bin_dir}/Qt5Widgets.dll
    DESTINATION .
    )

  ## Install Qt platform plugin
  install(FILES
    ${qt5_dir}/plugins/platforms/qwindows.dll
    DESTINATION platforms
    )

  ## Install qml components
  install(DIRECTORY "${qt5_dir}/qml/QtQuick"   DESTINATION .)  
  install(DIRECTORY "${qt5_dir}/qml/QtQuick.2" DESTINATION .)
  
  ## Install BOOST librarires
  find_library(boost_filesystem_dll     boost_filesystem-mt)
  find_library(boost_serialization_dll  boost_serialization-mt)
  find_library(boost_system_dll         boost_system-mt)
  install(FILES
    ${boost_filesystem_dll}
    ${boost_serialization_dll}
    ${boost_system_dll}
    DESTINATION .
    )

  ## Install other libraries
  find_library(bz2_dll bz2)
  find_library(eay32_dll eay32)
  find_library(freetype_dll freetype-6)
  find_library(gcc_sljl_dll gcc_s_sjlj-1)
  find_library(glib_dll glib-2.0-0)
  find_library(harfbuzz_dll harfbuzz-0)
  find_library(iconv_dll iconv-2)
  find_library(intl_dll intl-8)
  find_library(jpeg_dll jpeg-9)
  find_library(pcre16_dll pcre16-0)
  find_library(pcre_dll pcre-1)
  find_library(png16 png16-16)
  find_library(stdc++_dll stdc++-6)
  find_library(ssley32_dll ssleay32)
  find_library(zlib_dll zlib1)  
  install(FILES
    ${bz2_dll}
    ${eay32_dll}
    ${freetype_dll}
    ${gcc_sljl_dll}
    ${glib_dll}
    ${harfbuzz_dll}
    ${iconv_dll}
    ${intl_dll}
    ${jpeg_dll}
    ${pcre16_dll}
    ${pcre_dll}
    ${png16}
    ${stdc++_dll}
    ${ssley32_dll}
    ${zlib_dll}
    DESTINATION .
    )
else()
  install(TARGETS nina
    DESTINATION bin
    )  
endif()

