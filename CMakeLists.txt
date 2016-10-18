cmake_minimum_required( VERSION 3.5.0 )

#project name
get_filename_component( CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME )
project( ${CURRENT_DIR_NAME} )

#find packages
find_package( Qt5Core          REQUIRED )
find_package( Qt5Gui           REQUIRED )
find_package( Qt5Widgets       REQUIRED )
find_package( Qt5Network       REQUIRED )


#settings
set( ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}" )
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ROOT_DIR}/build/cmake/" )
set( CURRENT_SRC_PATH "${ROOT_DIR}/src" )

if(UNIX)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -O0")
endif(UNIX)

#includes
include( custom-tools )
include( cotire )

#load config
set( CONFIG_PATH "${ROOT_DIR}/config.in" )
set( CONFIG_TEMPLATE_PATH "${ROOT_DIR}/build/cmake/templates/config.in" )
load_config( ${CONFIG_PATH} ${CONFIG_TEMPLATE_PATH} )

set( CMAKE_PREFIX_PATH "${QT_PATH}" "${QT_PATH}/lib/cmake" ${CMAKE_PREFIX_PATH} )

include_directories( "${CURRENT_SRC_PATH}" )
include_directories( "${CMAKE_CURRENT_LIST_DIR}/common" )

#build file list
file( GLOB_RECURSE H_FILES "${CURRENT_SRC_PATH}/*.h" )
file( GLOB_RECURSE CPP_FILES "${CURRENT_SRC_PATH}/*.cpp" )

set( USER_FILES ${H_FILES} ${CPP_FILES} )

#wrapping
unset( MOC_LIST )
qt5_wrap_cpp( MOC_LIST ${H_FILES} OPTIONS "--no-notes" )

set( GENERATED_FILES ${MOC_LIST} )
set( ALL_FILES ${USER_FILES} ${GENERATED_FILES} )

apply_source_groups( USER_FILES ${CURRENT_SRC_PATH} "Sources" )
apply_source_groups( GENERATED_FILES ${CURRENT_SRC_PATH} "Generated" )

#compiling
add_executable( ${PROJECT_NAME} ${ALL_FILES} )

#linking
target_link_libraries( ${PROJECT_NAME} Qt5::Core )
target_link_libraries( ${PROJECT_NAME} Qt5::Gui )
target_link_libraries( ${PROJECT_NAME} Qt5::Widgets )
target_link_libraries( ${PROJECT_NAME} Qt5::Network )

#cotire
set_target_properties( ${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "common/common.h" )
set_target_properties( ${PROJECT_NAME} PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE )
cotire( ${PROJECT_NAME} )
