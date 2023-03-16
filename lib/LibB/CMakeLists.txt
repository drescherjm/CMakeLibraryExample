add_library(${PROJECT_NAME}LibB src/MathLibrary.cpp Include/MathLibrary.h)
target_include_directories(${PROJECT_NAME}LibB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include ${CMAKE_CURRENT_BINARY_DIR})

include(GenerateExportHeader) 

GENERATE_EXPORT_HEADER( ${PROJECT_NAME}LibB
             BASE_NAME ${PROJECT_NAME}
             EXPORT_MACRO_NAME ${PROJECT_NAME}_MATHLIBRARY_API
             EXPORT_FILE_NAME ${PROJECT_NAME}LibB_Export.h
             STATIC_DEFINE ${PROJECT_NAME}_BUILT_AS_STATIC
)

target_precompile_headers(${PROJECT_NAME}LibB
  PRIVATE
    <utility>
	<limits.h>
)

