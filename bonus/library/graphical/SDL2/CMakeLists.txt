cmake_minimum_required(VERSION 3.16.3)

project(etibSDL VERSION 1.0.1 DESCRIPTION "SDL implementation for etib")

find_package(SDL2 REQUIRED)

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
message("Debug mode SDL")
endif()

add_link_options(-lSDL2main -lSDL2_image -lSDL2)

include_directories(${INCLUDES})
include_directories(${SDL_INCLUDE_DIRS})
add_library(libsdl SHARED ${SOURCE} ${SOURCES_ENGINE})

set_target_properties(libsdl PROPERTIES PREFIX "")
set_target_properties(libsdl PROPERTIES OUTPUT_NAME "arcade_sdl2")
set_target_properties(libsdl PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
