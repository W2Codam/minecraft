cmake_minimum_required(VERSION 3.5)
project(paradox VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(Vulkan REQUIRED)

# Get all the source files inside the engine directory
include_directories(${CMAKE_SOURCE_DIR}/engine)
file(GLOB_RECURSE SOURCES "engine/*.cpp" "engine/*.hpp")
list(FILTER SOURCES EXCLUDE REGEX "main.cpp")

message(STATUS "SOURCES: ${SOURCES}")
message(STATUS "Debug Output: ${PROJECT_SOURCE_DIR}/bin/Debug")
message(STATUS "Release Output: ${PROJECT_SOURCE_DIR}/bin/Release")

# Depending on the OS use different main.cpp (e.g: engine/platform/win32/main.cpp)
if (WIN32)
    add_executable(paradox "engine/platform/win32/main.cpp" ${SOURCES})
elseif(UNIX)
    add_executable(paradox "engine/platform/unix/main.cpp" ${SOURCES})
endif()

add_subdirectory(libs/glfw)
target_link_libraries(paradox PRIVATE glfw)

add_subdirectory(libs/vma)
target_link_libraries(paradox PRIVATE GPUOpen::VulkanMemoryAllocator)

set_target_properties(paradox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/../bin/debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/../bin/release"
)