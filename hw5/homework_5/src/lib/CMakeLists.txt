add_library(mat_serialization serialize.cpp)
add_library(convert_dataset convert_dataset.cpp)

target_link_libraries(mat_serialization ${OpenCV_LIBS})
target_link_libraries(convert_dataset ${OpenCV_LIBS} mat_serialization)