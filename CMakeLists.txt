cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
cmake_policy(VERSION 2.6)

project(MoGS_Tinyxml)

set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/.")

foreach(p LIB INCLUDE)
	set(var CMAKE_INSTALL_${p}DIR)
	if(NOT IS_ABSOLUTE "${${var}}")
		set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
	endif()
endforeach()

add_library(MoGS_Tinyxml SHARED tinyxml2.cpp tinyxml2.h additionnal_tinyxml.cpp additionnal_tinyxml.h )

# generate the pks_config file
configure_file(MoGS_Tinyxml.pc.in MoGS_Tinyxml.pc @ONLY)

# install the pkgconfig files
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/MoGS_Tinyxml.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/lib/pkgconfig)
# install the include files
install(FILES tinyxml2.h additionnal_tinyxml.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/include/MoGS/MoGS_Tinyxml)
# install the library files
install( TARGETS "MoGS_Tinyxml" LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/lib  COMPONENT main)