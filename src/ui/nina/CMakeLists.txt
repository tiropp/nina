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
  Boost::filesystem
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

  ## Suffix for QT libraries
  if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
    set(dll_suffix "d")
  else()
    set(dll_suffix "")
  endif()
  
  ## Install Qt libraries
  get_property(qt5_core_dll TARGET Qt5::Core PROPERTY LOCATION)
  get_filename_component(qt5_bin_dir "${qt5_core_dll}" DIRECTORY)
  set(qt5_dir "${qt5_bin_dir}/..")
  
  install(FILES
    ${qt5_bin_dir}/Qt5Core${dll_suffix}.dll
    ${qt5_bin_dir}/Qt5Network${dll_suffix}.dll
    ${qt5_bin_dir}/Qt5Qml${dll_suffix}.dll
    ${qt5_bin_dir}/Qt5QmlModels${dll_suffix}.dll
    ${qt5_bin_dir}/Qt5QmlWorkerScript${dll_suffix}.dll
    ${qt5_bin_dir}/Qt5Gui${dll_suffix}.dll
    ${qt5_bin_dir}/Qt5Quick${dll_suffix}.dll
    ${qt5_bin_dir}/Qt5QuickControls2${dll_suffix}.dll
    ${qt5_bin_dir}/Qt5QuickTemplates2${dll_suffix}.dll
    ${qt5_bin_dir}/Qt5Svg${dll_suffix}.dll
    ${qt5_bin_dir}/Qt5Widgets${dll_suffix}.dll
    DESTINATION .
    )

  ## Install Qt platform plugin
  install(FILES
    ${qt5_dir}/plugins/platforms/qwindows${dll_suffix}.dll
    DESTINATION platforms
    )

  ## Install qml components
  install(DIRECTORY "${qt5_dir}/qml/QtQuick"   DESTINATION .)  
  install(DIRECTORY "${qt5_dir}/qml/QtQuick.2" DESTINATION .)

  ## Add suffix '.dll' for library search
  list(APPEND CMAKE_FIND_LIBRARY_SUFFIXES ".dll")
  message(STATUS "CMAKE_FIND_LIBRARY_SUFFIXES: ${CMAKE_FIND_LIBRARY_SUFFIXES}")

  ## Install BOOST librarires
  find_library(boost_filesystem_dll       boost_filesystem-mt-x64       REQUIRED)
  find_library(boost_serialization_dll    boost_serialization-mt-x64    REQUIRED)
  find_library(boost_system_dll           boost_system-mt-x64           REQUIRED)
  find_library(boost_locale_dll           boost_locale-mt-x64           REQUIRED)
  find_library(boost_stacktrace_basic_dll boost_stacktrace_basic-mt-x64 REQUIRED)
  install(FILES
    ${boost_filesystem_dll}
    ${boost_serialization_dll}
    ${boost_system_dll}
    ${boost_locale_dll}
    ${boost_stacktrace_basic_dll}
    DESTINATION .
  )

  ## Install other libraries
  find_library(bz2_dll           bz2          PATHS bin REQUIRED)
  find_library(winpthread_dll    winpthread-1 PATHS bin REQUIRED)
  find_library(gcc_s_seh_dll     gcc_s_seh-1  PATHS bin REQUIRED)
  find_library(stdc++_dll        stdc++-6     PATHS bin REQUIRED)
  find_library(icuin_dll         icuin74      PATHS bin REQUIRED)
  find_library(icuuc_dll         icuuc74      PATHS bin REQUIRED)
  find_library(pcre2_16_dll      pcre2-16-0   PATHS bin REQUIRED)
  find_library(pcre2_8_dll       pcre2-8-0    PATHS bin REQUIRED)
  find_library(zlib_dll          zlib1        PATHS bin REQUIRED)
  find_library(zstd_dll          zstd         PATHS bin REQUIRED)
  find_library(harfbuzz_dll      harfbuzz-0   PATHS bin REQUIRED)
  find_library(png_dll           png16-16     PATHS bin REQUIRED)
  find_library(iconv_dll         iconv-2      PATHS bin REQUIRED)
  find_library(freetype_dll      freetype-6   PATHS bin REQUIRED)
  find_library(glib_dll          glib-2.0-0   PATHS bin REQUIRED)
  find_library(intl_dll          intl-8       PATHS bin REQUIRED)
  find_library(icudt_dll         icudt74      PATHS bin REQUIRED)
  find_library(crypto_dll        crypto-3-x64 PATHS bin REQUIRED)
  find_library(ssl_dll           ssl-3-x64    PATHS bin REQUIRED)
  find_library(brotlidec_dll     brotlidec    PATHS bin REQUIRED)
  find_library(brotlicommon_dll  brotlicommon PATHS bin REQUIRED)
  install(FILES
    ${bz2_dll}
    ${winpthread_dll}
    ${gcc_s_seh_dll}
    ${stdc++_dll}
    ${icuin_dll}
    ${icuuc_dll}
    ${pcre1_dll}
    ${pcre2_8_dll}
    ${pcre2_16_dll}
    ${zlib_dll}
    ${zstd_dll}
    ${harfbuzz_dll}
    ${png_dll}
    ${iconv_dll}
    ${freetype_dll}
    ${glib_dll}
    ${intl_dll}
    ${icudt_dll}
    ${crypto_dll}
    ${ssl_dll}
    ${brotlidec_dll}
    ${brotlicommon_dll}
    DESTINATION .
    )
else()
  install(TARGETS nina
    DESTINATION bin
    )  
endif()

