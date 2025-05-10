# set (SOURCES
	# test_long_number.cpp
# )

# add_executable(test_long_number ${SOURCES})
# target_link_libraries(test_long_number
	# gtest_main
	# long_number_lib
# )

# add_test(test_long_number test_long_number)


add_executable(ilyatest ilyatest.cpp)
target_link_libraries(ilyatest
	gtest_main
	long_number_lib
)

add_test(ilyatest ilyatest)