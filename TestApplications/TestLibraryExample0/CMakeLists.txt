find_package(LibraryExample REQUIRED COMPONENTS LibA LibB)

set(LOCAL_TARGET_NAME ${PROJECT_NAME}Exe1)

add_executable(${LOCAL_TARGET_NAME} main.cxx)
target_link_libraries(${LOCAL_TARGET_NAME} LibEX::LibraryExampleLibA LibEX::LibraryExampleLibB)

if (WIN32)
	add_custom_command(TARGET ${LOCAL_TARGET_NAME} POST_BUILD
	  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${LOCAL_TARGET_NAME}> $<TARGET_FILE_DIR:${LOCAL_TARGET_NAME}>
	  COMMAND_EXPAND_LISTS
	)
 endif()