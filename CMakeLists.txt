cmake_minimum_required(VERSION 3.20)

project(my_cool_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

add_executable(my_cool_project ${SOURCES})

file(GLOB_RECURSE COMPILED_LIBRARIES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.a"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.so"
)

target_link_libraries(my_cool_project PRIVATE
    ${COMPILED_LIBRARIES}
)

target_include_directories(my_cool_project PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# System/package dependencies go here:
# find_package(SDL3 CONFIG REQUIRED)
# target_link_libraries(my_cool_project PRIVATE SDL3::SDL3)
