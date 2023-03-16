
add_executable(${PROJECT_NAME}Exe main.cxx)
target_link_libraries(${PROJECT_NAME}Exe ${PROJECT_NAME}LibA ${PROJECT_NAME}LibB)

set_target_properties(${PROJECT_NAME}Exe PROPERTIES FOLDER CMakeDevelopment/${PROJECT_NAME})