cmake_minimum_required(VERSION 3.16.3)

project(arcade)

set(CMAKE_CXX_STANDARD 20)

file(GLOB files "library/graphical/*" "library/game/*")
foreach(file ${files})
add_subdirectory(${file})
endforeach()

file(GLOB_RECURSE SOURCE "src/*.cpp")
file(GLOB_RECURSE SOURCES_ENGINE "library/engine/src/*.cpp")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g3 -ggdb)
    message("Debug mode arcade")
endif()

include_directories(library/engine/include)
include_directories(include)

add_executable(arcade ${SOURCE} ${SOURCES_ENGINE})

target_compile_features(arcade PRIVATE cxx_std_17)
target_link_libraries(arcade PRIVATE ${CMAKE_DL_LIBS})
set_target_properties(arcade PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../")