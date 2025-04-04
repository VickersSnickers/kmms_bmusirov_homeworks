#include "long_number.hpp"
#include <iostream>
using namespace std;

int main() {
    int pos = 0;
    char str[4] = {'a', 'b', 'd', 'e'};
    int length = 0;
    for (int i = pos; str[i] != '\0'; ++i) ++length;
    cout << length;
}