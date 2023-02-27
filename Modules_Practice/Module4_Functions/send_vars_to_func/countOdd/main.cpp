// Напишите функцию countOdd, которая принимает на вход массив и возвращает количество четных элементов массива.
#include <iostream>

int coundOdd(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        (array[i] % 2 == 0) ? ++sum:0;
    }
    return sum;
}
int main() {
    int size, sum;
    std::cout << "Array size:" << std::endl;
    std::cin >> size;

    int* array = new int[size];

    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
    sum = coundOdd(array, size);
    std::cout << "Sum: " << sum << std::endl;


}