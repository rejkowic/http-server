cmake_minimum_required(VERSION 3.9)

project(http-server-test)

add_subdirectory(app-factory)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} http-server app-factory)
