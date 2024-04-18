cmake_minimum_required(VERSION 3.16.3)

project(etibNCURSE VERSION 1.0.1 DESCRIPTION "NCURSE implementation for etib")

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
    message("Debug mode NCURSE")
endif()

include_directories(${INCLUDES})
add_library(libncurse SHARED ${SOURCE} ${SOURCES_ENGINE})

target_link_libraries(libncurse PRIVATE ncurses)
set_target_properties(libncurse PROPERTIES PREFIX "")
set_target_properties(libncurse PROPERTIES OUTPUT_NAME "arcade_ncurse")
set_target_properties(libncurse PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
