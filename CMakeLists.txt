cmake_minimum_required (VERSION 3.7.0)
project(nina VERSION 0.2.4 LANGUAGES CXX)


######################
## Compiler options ##
######################
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")


###############
## Libraries ##
##############

##
## BOOST
##
find_package(Boost REQUIRED
  COMPONENTS unit_test_framework filesystem serialization locale)
# add_library(boost INTERFACE IMPORTED)
# set_property(TARGET boost PROPERTY
#   INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#   )


##
## QT
##
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the Qt libraries
find_package(Qt5 COMPONENTS Quick Qml Widgets QuickControls2)
if( MINGW )
  set_property(TARGET Qt5::Core
    APPEND 
    PROPERTY INTERFACE_LINK_LIBRARIES "-lz -lws2_32 -lwinmm -lpcre16"
    )
  set_property(TARGET Qt5::Widgets
    APPEND 
    PROPERTY INTERFACE_LINK_LIBRARIES "-luxtheme"
    )
  set_property(TARGET Qt5::Network
    APPEND 
    PROPERTY INTERFACE_LINK_LIBRARIES "-lssl -lcrypto -lz -lcrypt32 -lws2_32 -liphlpapi"
    )
  set_property(TARGET Qt5::Gui
    APPEND 
    PROPERTY INTERFACE_LINK_LIBRARIES "-lharfbuzz -lpng -lpcre16"
    )
endif()



#############
## SUBDIRS ##
#############
add_subdirectory(src)


#############
## PACKAGE ##
#############
set(CPACK_PACKAGE_VENDOR "tiropp")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
include(CPack)
