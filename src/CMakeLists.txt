cmake_minimum_required(VERSION 3.18)
project(vk42)

set(CMAKE_CXX_STANDARD 20)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(Vulkan REQUIRED)

add_subdirectory(libs/glfw)
add_subdirectory(libs/vma)

# Get all the source files inside the engine directory
include_directories(${CMAKE_SOURCE_DIR}/engine)
file(GLOB_RECURSE SOURCES "engine/*.cpp" "engine/*.hpp")
list(FILTER SOURCES EXCLUDE REGEX "main.cpp")

message(STATUS "SOURCES: ${SOURCES}")

# Depending on the OS use different main.cpp (e.g: engine/platform/win32/main.cpp)
if (WIN32)
    add_executable(vk42 "engine/platform/win32/main.cpp" ${SOURCES})
elseif(UNIX)
    add_executable(vk42 "engine/platform/unix/main.cpp" ${SOURCES})
endif()