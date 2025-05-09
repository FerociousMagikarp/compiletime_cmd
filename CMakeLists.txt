cmake_minimum_required(VERSION 3.8)

project(ct_cmd)

set(CMAKE_CXX_STANDARD 20)
include_directories(
    ${PROJECT_SOURCE_DIR}
)
file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${MAIN_SRC})
