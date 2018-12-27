cmake_minimum_required(VERSION 3.12)
project(opengl_clion_tng)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/glew/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/glm/include)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/libs)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/glew/libs)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/glm/libs)

#glm - x64
#glew - x32
#glfw - x32

add_executable(opengl_clion_tng main.cpp)

target_link_libraries(opengl_clion_tng glfw3 libglew32 ${OPENGL_LIBRARIES})