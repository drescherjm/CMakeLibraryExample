cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0074 NEW)

set(CMAKE_CXX_STANDARD 17)

project(LibraryExample)

#########################################################################################

option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" ON)

SET (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all libraries.")
SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all executables.")

#########################################################################################
 
add_subdirectory(exec)
add_subdirectory(lib)
