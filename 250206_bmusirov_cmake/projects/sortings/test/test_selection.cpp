#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "selection_sort.hpp"

TEST(ArraysEqual, AnyElementsCount) {
	std::vector<int> actual = {1, 8, 2, 5, 3, 11};
	selection_sort(actual, actual.size());
	std::vector<int> expected = {1, 4, 3, 5, 8, 11};
	
	ASSERT_EQ(expected.size(), actual.size())
		<< "Different sizes of actual and sorted arrays";
		
	for (int i = 0; i < actual.size(); ++i) {
		ASSERT_EQ(expected[i], actual[i])
			<< "Expected and sorted arrays differ in element with index"
			<< i;
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}