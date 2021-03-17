#include "../ArrayUtils.h"
#include <iostream>

int main() {
    int arr[5] = { 4, 7, 1, 3, 8 };

    std::cout << "4, 7, 1, 3, 8\n";
    selectionSort(arr, 5);
    for (int i : arr) std::cout << i << " ";
}
