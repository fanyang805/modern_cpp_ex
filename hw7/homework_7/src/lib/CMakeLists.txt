add_library(utils utils.cpp)
add_library(kmeans kMeans.cpp)
add_library(serialization serialize.cpp convert_dataset.cpp)
add_library(bow_dictionary bowdictionary.cpp)

target_link_libraries(utils ${OpenCV_LIBS})
target_link_libraries(kmeans ${OpenCV_LIBS} utils)
target_link_libraries(serialization ${OpenCV_LIBS})
target_link_libraries(bow_dictionary ${OpenCV_LIBS} kmeans)