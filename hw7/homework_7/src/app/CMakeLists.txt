add_executable(test_func test_func.cpp)
add_executable(test test.cpp)
add_executable(learncv learncv.cpp)

target_link_libraries(test_func ${OpenCV_LIBS})
target_link_libraries(test utils ${OpenCV_LIBS})
target_link_libraries(learncv ${OpenCV_LIBS})