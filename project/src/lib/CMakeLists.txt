add_library(convert_dataset serialize.cpp convert_dataset.cpp)
add_library(utils utils.cpp)

target_link_libraries(convert_dataset ${OpenCV_LIBS})
target_link_libraries(utils ${OpenCV_LIBS})