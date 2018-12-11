#include "roman.h"
#include <iostream>

int main() {
    Roman_int arr[100];
    std::cin >> arr[0] >> arr[1];
    std::cout << arr[0] + arr[1] << std::endl;
    std::cout << arr[0].as_int() << std::endl;
    Roman_int b;
    b = arr[0] + arr[1];
    std::cout << b.as_int();
    std::cout.op
}