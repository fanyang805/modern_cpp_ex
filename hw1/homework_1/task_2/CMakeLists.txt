cmake_minimum_required(VERSION 3.1)
project(hw1_task2)
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/include/ipb_arthmetic/)
include_directories(${PROJECT_SOURCE_DIR}/abc/)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install/)


install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/)

add_subdirectory(src)