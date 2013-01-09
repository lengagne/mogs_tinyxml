cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
cmake_policy(VERSION 2.6)

project(MoGS_tinyxml)
include(GNUInstallDirs)
#enable_testing()

#CMAKE_BUILD_TOOL

################################
# set lib version here

set(GENERIC_LIB_VERSION "1.0.8")
set(GENERIC_LIB_SOVERSION "1")


################################
# Add common source 

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/.")


################################
# Add definitions

if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

################################
# Add targets
set(BUILD_STATIC_LIBS ON CACHE BOOL "Set to ON to build static libraries")
if(BUILD_STATIC_LIBS)
	add_library(MoGS_tinyxmlstatic STATIC tinyxml2.cpp tinyxml2.h additionnal_tinyxml.cpp additionnal_tinyxml.h)
	set_target_properties(MoGS_tinyxmlstatic PROPERTIES OUTPUT_NAME MoGS_tinyxml)
endif(BUILD_STATIC_LIBS)
add_library(MoGS_tinyxml SHARED tinyxml2.cpp tinyxml2.h additionnal_tinyxml.cpp additionnal_tinyxml.h )
set_target_properties(MoGS_tinyxml PROPERTIES
	VERSION "${GENERIC_LIB_VERSION}"
	SOVERSION "${GENERIC_LIB_SOVERSION}")


if(BUILD_STATIC_LIBS)
	install(TARGETS MoGS_tinyxml MoGS_tinyxmlstatic
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
else(BUILD_STATIC_LIBS)
	install(TARGETS MoGS_tinyxml
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif(BUILD_STATIC_LIBS)
install(FILES tinyxml2.h additionnal_tinyxml.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

foreach(p LIB INCLUDE)
	set(var CMAKE_INSTALL_${p}DIR)
	if(NOT IS_ABSOLUTE "${${var}}")
		set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
	endif()
endforeach()

configure_file(tinyxml2.pc.in tinyxml2.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/tinyxml2.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)

