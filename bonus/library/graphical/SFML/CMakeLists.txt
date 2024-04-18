cmake_minimum_required(VERSION 3.16.3)

project(etibSFML VERSION 1.0.1 DESCRIPTION "SFML implementation for etib")

find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

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
    message("Debug mode SFML")
endif()

include_directories(${INCLUDES})
add_library(libsfml SHARED ${SOURCE} ${SOURCES_ENGINE})

target_link_libraries(libsfml PRIVATE sfml-graphics sfml-window sfml-audio sfml-system sfml-network)
set_target_properties(libsfml PROPERTIES PREFIX "")
set_target_properties(libsfml PROPERTIES OUTPUT_NAME "arcade_sfml")
set_target_properties(libsfml PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
