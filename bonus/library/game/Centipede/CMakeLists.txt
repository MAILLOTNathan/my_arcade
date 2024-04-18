cmake_minimum_required(VERSION 3.16.3)

project(Centipede VERSION 1.0.1 DESCRIPTION "Etib's version of Centipede")

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
    message("Debug mode Centipede")
endif()

include_directories(${INCLUDES})
add_library(centipede SHARED ${SOURCE} ${SOURCES_ENGINE})

set_target_properties(centipede PROPERTIES PREFIX "")
set_target_properties(centipede PROPERTIES OUTPUT_NAME "arcade_centipede")
set_target_properties(centipede PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")