cmake_minimum_required(VERSION 3.16.3)

project(etibOpenGL VERSION 1.0.1 DESCRIPTION "OpenGL implementation for etib")

find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE "src/*.cpp")
file(GLOB_RECURSE SOURCES_ENGINE "../library/engine/src/*.cpp")

set(INCLUDES
"../../engine/include/"
"../library/engine/include/"
"./include/"
)

set(OPENGL_LIBS
    "GL"
    "glfw"
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
add_compile_options(-g3 -ggdb)
message("Debug mode OPENGL")
endif()


include_directories(${INCLUDES})
include_directories(${SDL_INCLUDE_DIRS})
add_library(libOpenGL SHARED ${SOURCE} ${SOURCES_ENGINE})

target_link_libraries(libOpenGL PRIVATE ${OPENGL_LIBS})
set_target_properties(libOpenGL PROPERTIES PREFIX "")
set_target_properties(libOpenGL PROPERTIES OUTPUT_NAME "arcade_opengl")
set_target_properties(libOpenGL PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
