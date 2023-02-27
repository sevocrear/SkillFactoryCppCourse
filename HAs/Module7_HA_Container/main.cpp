/**
 * В данном задании, мы предлагаем вам написать контейнер данных IntegerArray — объект, который хранит целые числа и способен вычислить собственный размер во время выполнения программы.

 * За основу вы можете взять контейнер IntArray. Однако ваша задача — использовать вместо ассертов механизм исключения C++ , 
 * генерировать исключения-наследники exception — для выхода за пределы массива — bad_range, предоставление неправильной длины массиву bad_length. 
 * Напишите объявление и реализацию данного контейнера в двух разных файлах (h и сpp), а в функции main протестируйте все пограничные случаи и убедитесь, что ваш контейнер безопасен!
*/
#include <iostream>
#include "include/ArrayContainer.hpp"

int main()
{
    try {
        // Declare an array with 10 elements
        IntArray array(10);

        // Fill the array with numbers 1 through 10
        for (int i{ 0 }; i<10; ++i)
            array[i] = i+1;

        //Copy array
        IntArray array2;
        array.copy(array2);

        // Print out all the numbers
        for (int i{ 0 }; i<array2.getLength(); ++i)
            std::cout << array2[i] << ' ';
        std::cout << '\n';

        // Resize the array to 8 elements
        array.resize(8);

        // Insert the number 20 before element with index 5
        array.insertBefore(20, 5);

        // Remove the element with index 3
        array.remove(3);

        // Add 30 and 40 to the end and beginning
        array.insertAtEnd(30);
        array.insertAtBeginning(40);

        // Find Element
        int value = 41;
        std:: cout << "idx of element "  << value << " = " <<  array.findElement(value) << std::endl;

        // Print out all the numbers
        for (int i{ 0 }; i<array.getLength(); ++i)
            std::cout << array[i] << ' ';
        
        
        std::cout << '\n';
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}