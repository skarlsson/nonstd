add_executable(test_decimal test_decimal.cpp)
target_link_libraries(test_decimal gtest ${ALL_LIBS})

add_executable(test_timestamps test_timestamps.cpp)
target_link_libraries(test_timestamps gtest ${ALL_LIBS})

