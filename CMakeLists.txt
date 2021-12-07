cmake_minimum_required(VERSION 3.10)
project(qubit-simulation VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# read filenames from directories into respective variables
aux_source_directory(examples EXAMPLE_SRCS)
aux_source_directory(src PROJECT_SRCS)

include_directories(include)

set(CMAKE_BUILD_TYPE Debug)

# enable all warnings for Clang and GCC
if (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang" OR
        ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Weffc++")
endif ()

foreach (SRC ${EXAMPLE_SRCS})
    # get filename without extension into TARGET_NAME
    get_filename_component(TARGET_NAME ${SRC} NAME_WE)
    # add an executable for each example source
    add_executable(${TARGET_NAME} ${SRC} ${PROJECT_SRCS})
endforeach ()
