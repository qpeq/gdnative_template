cmake_minimum_required(VERSION 3.16)

project({{cookiecutter.project_name}}	
    VERSION 0.1.0
	DESCRIPTION "{{cookiecutter.project_description}}"
    LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_library(${PROJECT_NAME} SHARED 
    source/simple.h
    source/simple.cpp
    source/entry.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE CONAN_PKG::godot-cpp)

if(MSVC)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/$<TARGET_FILE_NAME:${PROJECT_NAME}>
            ${PROJECT_SOURCE_DIR}/../$<TARGET_FILE_NAME:${PROJECT_NAME}>
)
