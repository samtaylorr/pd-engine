cmake_minimum_required(VERSION 3.17)

project("pd-engine")

file(GLOB MY_SOURCES "src/*.cpp" "src/*.h" "include/pd-engine/*.h" "vendor/glad/src/glad.c")
add_executable("${PROJECT_NAME}" "${MY_SOURCES}")

# These are the options we select for building GLFW as a library
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)        # Don't build Documentation
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)       # Don't build Tests
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)    # Don't build Examples
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)           # Don't build Installation Information
set(GLFW_USE_HYBRID_HPG ON CACHE BOOL "" FORCE)     # Add variables to use High Performance Graphics Card if available
add_subdirectory(vendor/glfw)                       # Build the GLFW project to use later as a library

include_directories(
    vendor/glfw/include
    vendor/glad/include
)

target_link_libraries(${PROJECT_NAME} glfw)
