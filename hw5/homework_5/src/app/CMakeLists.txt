# add_executable(write_binary write_binary.cpp)
# add_executable(read_binary read_binary.cpp)
add_executable(test_convert test_convert.cpp)
add_executable(test_binary test_binary.cpp)

target_link_libraries(test_convert convert_dataset ${OpenCV_LIBS} mat_serialization)
target_link_libraries(test_binary ${OpenCV_LIBS} mat_serialization)

