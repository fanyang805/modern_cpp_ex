cmake_minimum_required(VERSION 3.10)
project(hw2_task1)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/lib/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

# message(STUTUS "The PROJECT_SOURCE_DIR is ${PROJECT_SOURCE_DIR}")
# message(STUTUS "The CMAKE_BINARY_DIR is ${CMAKE_BINARY_DIR}")
# message(STUTUS "The CMAKE_SOURCE_DIR is ${CMAKE_SOURCE_DIR}")
# message(STUTUS "The CMAKE_CURRENT_BINARY_DIR is ${CMAKE_CURRENT_BINARY_DIR}")
# message(STUTUS "The CMAKE_CURRENT_SOURCE_DIR is ${CMAKE_CURRENT_SOURCE_DIR}")


add_subdirectory(src)