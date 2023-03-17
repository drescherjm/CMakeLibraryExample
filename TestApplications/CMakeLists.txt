cmake_minimum_required(VERSION 3.21)
cmake_policy(SET CMP0074 NEW)

set(CMAKE_CXX_STANDARD 17)

project(TestLibraryExample)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    if(DEFINED ENV{CMAKE_INSTALL_PREFIX})
		set(CMAKE_PREFIX_PATH $ENV{CMAKE_INSTALL_PREFIX} 
			CACHE PATH "Force path to set CMAKE_INSTALL_PREFIX" FORCE)
		set(CMAKE_INSTALL_PREFIX "$ENV{CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}" 
			CACHE PATH "Force path to set CMAKE_INSTALL_PREFIX" FORCE)
	endif()
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)


message(STATUS Prefix=${CMAKE_PREFIX_PATH})

#########################################################################################

SET (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all libraries.")
SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all executables.")

#########################################################################################

macro(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        SET(dirlist ${dirlist} ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
endmacro()

#########################################################################################

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

FOREACH(subdir ${SUBDIRS})
    ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()

#########################################################################################