cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
cmake_policy(VERSION 2.6)

project(MoGS_Tinyxml)

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
  set(MoGS_Tinyxml_LIBRARY_DIRS "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/lib" CACHE INTERNAL "" )
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

file(
	GLOB_RECURSE
	source_files_MoGS_Tinyxml
	src/*
)

file(
	GLOB_RECURSE
	header_files_MoGS_Tinyxlk
	include/*.h
)


add_library(MoGS_Tinyxml SHARED
	    ${source_files_MoGS_Tinyxml})

# generate the pks_config file
configure_file(MoGS_Tinyxml.pc.in MoGS_Tinyxml.pc @ONLY)

# install the pkgconfig files
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/MoGS_Tinyxml.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/lib/pkgconfig)
# install the include files
install(FILES ${header_files_MoGS_Tinyxlk} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/include/MoGS/MoGS_Tinyxml)
# install the library files
install( TARGETS "MoGS_Tinyxml" LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/lib  COMPONENT main)