add_library(bow_dictionary bowdictionary.cpp kMeans.cpp utils.cpp)
add_library(histogram histogram.cpp)

target_link_libraries(bow_dictionary ${OpenCV_LIBS})
target_link_libraries(histogram bow_dictionary)