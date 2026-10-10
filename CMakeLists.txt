cmake_minimum_required(VERSION 3.28)
project(project)

# Configure C++ Compiler
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wconversion -Wpedantic -Wshadow")

# Configure output directories for compiled binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Global include directory
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/include
)

# # --- INTERNAL LIBRARY ---
file(GLOB_RECURSE LIBRARY_FILES CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)
add_library(library STATIC ${LIBRARY_FILES})

# --- EXECUTABLE ---
file(GLOB_RECURSE BINARY_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/app/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/app/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/app/*.h"
)
add_executable(program ${BINARY_FILES})

# --- COMPILED LIBRARIES ---
file(GLOB SHARED_LIBRARY_FILES "${CMAKE_CURRENT_SOURCE_DIR}/external/lib/shared/*.so")
file(GLOB STATIC_LIBRARY_FILES "${CMAKE_CURRENT_SOURCE_DIR}/external/lib/static/*.a")

## Linking
target_link_libraries(program
    ${SHARED_LIBRARY_FILES}
    ${STATIC_LIBRARY_FILES}
)

target_link_libraries(program library) # Automatically link the internal library
