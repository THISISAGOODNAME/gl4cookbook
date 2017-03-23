cmake_minimum_required(VERSION 3.5)
project(gl4cookbook)

# GLFW3
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(3rd_party/glfw)

# glm
include_directories(
        3rd_party/glad/include/
        3rd_party/glfw/include/
        3rd_party/glm/)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

set(COMMON_LIBS glfw ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})

add_subdirectory(boilerplate)
