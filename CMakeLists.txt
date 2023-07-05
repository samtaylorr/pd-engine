cmake_minimum_required(VERSION 3.17)

project("pd-engine")

file(GLOB MY_SOURCES "src/*.cpp" "src/*.h" "include/pd-engine/*.h" "lib/glad/src/glad.c" "src/components/*.cpp" "include/pd-engine/components/*.h")
add_executable("${PROJECT_NAME}" "${MY_SOURCES}")

file(COPY "./resources" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY "./shaders" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# These are the options we select for building GLFW as a library
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)        # Don't build Documentation
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)       # Don't build Tests
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)    # Don't build Examples
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)           # Don't build Installation Information
set(GLFW_USE_HYBRID_HPG ON CACHE BOOL "" FORCE)     # Add variables to use High Performance Graphics Card if available
add_subdirectory(lib/glfw)                       # Build the GLFW project to use later as a library
add_subdirectory(lib/glm)
include_directories(
    lib/glfw/include
    lib/glad/include
    lib/glm
    include/
)

target_compile_options(${PROJECT_NAME} PUBLIC -std=c++20)
target_link_libraries(${PROJECT_NAME} glfw glm)
