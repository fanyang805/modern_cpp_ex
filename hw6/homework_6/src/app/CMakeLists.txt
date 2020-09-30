# add_executable(test_iotool test_iotools.cpp)
add_executable(test_init test_init.cpp)
add_executable(test_pgm test_pgm.cpp)
add_executable(test_hist test_hist.cpp)

# target_link_libraries(test_iotool iotools)
target_link_libraries(test_init image)
target_link_libraries(test_pgm image iotools)
target_link_libraries(test_hist image iotools)
