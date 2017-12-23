cmake_minimum_required(VERSION 3.9)

project(http-server)

add_subdirectory(test)

set(CMAKE_CXX_STANDARD 17)
add_library(${PROJECT_NAME} src/HttpServer.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC interface)
