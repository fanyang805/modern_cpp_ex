add_executable(test test.cpp)

target_link_libraries(test bow_dictionary ${OpenCV_LIBS})