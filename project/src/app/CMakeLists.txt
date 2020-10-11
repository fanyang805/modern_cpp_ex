add_executable(create_data_bin create_data_bin.cpp)

target_link_libraries(create_data_bin utils convert_dataset ${OpenCV_LIBS})