cmake_minimum_required(VERSION 3.16.3)

project(Snake VERSION 1.0.1 DESCRIPTION "Etib's version of Snake")

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE "src/*.cpp")
file(GLOB_RECURSE SOURCES_ENGINE "../../engine/src/*.cpp")

set(INCLUDES
    "../../engine/include/"
    "./include/"
    "${CMAKE_SOURCE_DIR}/include"
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g3 -ggdb)
    message("Debug mode Snake")
endif()

include_directories(${INCLUDES})
add_library(snake SHARED ${SOURCE} ${SOURCES_ENGINE})

set_target_properties(snake PROPERTIES PREFIX "")
set_target_properties(snake PROPERTIES OUTPUT_NAME "arcade_snake")
set_target_properties(snake PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")