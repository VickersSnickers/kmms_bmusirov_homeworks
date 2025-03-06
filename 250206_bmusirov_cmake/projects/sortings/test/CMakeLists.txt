set (SOURCES
	test_selection.cpp
)

add_executable(test_selection ${SOURCES})
target_link_libraries(test_selection
	gtest_main
	gmock_main
	selection_sort_lib
)

add_test(test_selection test_selection)