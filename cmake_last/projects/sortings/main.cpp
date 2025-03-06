#include <iostream>
#include "selection_sort.hpp"

int main() {
	std::vector<int> arr = {1, 8, 2, 5, 3, 11};
	std::cout << "Array before sorting: ";
	for (int i = 0; i < arr.size(); ++i){
		std::cout << " " << arr[i];
	}
	std::cout << std::endl;

	selection_sort(arr, arr.size());

	std::cout << "Array after sorting: ";
    for (int i = 0; i < arr.size(); ++i){
            std::cout << " " << arr[i];
    }
    std::cout << std::endl;

	std::system("PAUSE");
	return 0;
}

