find_package(Catch2 REQUIRED)

add_executable(test_vector test_named_vector.cpp)

target_link_libraries(test_vector ipb_algorithm Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(test_vector)