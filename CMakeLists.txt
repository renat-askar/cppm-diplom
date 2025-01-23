cmake_minimum_required(VERSION 3.22)

project(simrace)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(simrace main.cpp)

add_subdirectory(simraceObjects)

target_link_libraries(simrace PUBLIC simraceObjects)

target_include_directories(simrace PUBLIC races vehicles)

add_custom_command(TARGET simrace POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:simraceObjects>              
    $<TARGET_FILE_DIR:simrace>)
