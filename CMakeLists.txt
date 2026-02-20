cmake_minimum_required(VERSION 4.2.3 FATAL_ERROR)

set(PROJECT_NAME GalinaEngine)
project(${PROJECT_NAME})

#set(CMAKE_CXX_STANDART 17)

find_package(Vulkan REQUIRED)


add_executable(${PROJECT_NAME} src/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)
add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)
