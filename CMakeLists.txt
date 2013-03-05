cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
cmake_policy(VERSION 2.6)

project(MoGS_Tinyxml)

set( CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /lib /usr/lib /usr/local/lib )
set( CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /usr/include /usr/local/include )
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake" )

set ( INSTALL_BIN_PATH bin )
set ( INSTALL_LIB_PATH lib )
set ( INSTALL_AR_PATH lib )
set ( INSTALL_HEADERS_PATH include )

foreach(p LIB INCLUDE)
	set(var CMAKE_INSTALL_${p}DIR)
	if(NOT IS_ABSOLUTE "${${var}}")
		set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
	endif()
endforeach()

# if the compilation is done for whole the project
if(MoGS_GLOBAL_COMPILED)
  set(MoGS_Tinyxml_MODULE_COMPILED "TRUE" CACHE INTERNAL "")
  set(MoGS_Tinyxml_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE INTERNAL "" )
  set(MoGS_Tinyxml_LIBRARY_DIRS "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/lib/${CMAKE_BUILD_TYPE}" CACHE INTERNAL "" )
  set(MoGS_Tinyxml_LIBRARIES  -lMoGS_Tinyxml CACHE INTERNAL "")
  set(MoGS_Tinyxml_GLOBAL_COMPILED "TRUE" CACHE INTERNAL "")
else (MoGS_GLOBAL_COMPILED)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse2")
  set(CMAKE_VERBOSE_MAKEFILE OFF)
  set(PROJECT_CONTACT lengagne@gmail.com)
endif (MoGS_GLOBAL_COMPILED)

set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})

include_directories(	./include )

file(	GLOB_RECURSE
	source_files_MoGS_Tinyxml
	src/*
)

file(	GLOB_RECURSE
	header_files_MoGS_Tinyxml
	include/*.h
)

add_library(MoGS_Tinyxml SHARED
	    ${source_files_MoGS_Tinyxml})

# install the include files
set(INSTALL_INCLUDE_DIRS ${CMAKE_INSTALL_INCLUDEDIR}/include/MoGS/MoGS_Tinyxml)

install(FILES ${header_files_MoGS_Tinyxml} DESTINATION ${INSTALL_INCLUDE_DIRS})
# install the library files
install( TARGETS "MoGS_Tinyxml" LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/lib  COMPONENT main)

### Configure file

configure_file(MoGS_TinyxmlConfig.cmake.in "${PROJECT_BINARY_DIR}/MoGS_TinyxmlConfig.cmake" @ONLY)

set ( INSTALL_LIB_PATH lib )

install ( FILES "${PROJECT_BINARY_DIR}/MoGS_TinyxmlConfig.cmake"
      DESTINATION "${INSTALL_LIB_PATH}/MoGS_Tinyxml" COMPONENT dev ) 
