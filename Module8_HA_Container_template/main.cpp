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
        const int length = 10;
        IntArray<float, length> array;

        // Fill the array with numbers 1 through 10
        for (int i{ 0 }; i<length; ++i)
            array[i] = i+1;

        // Print out all the numbers
        for (int i{ 0 }; i<array.getLength(); ++i)
            std::cout << array[i] << ' ';
        //Copy array
        IntArray<float, length> array2;
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
        // Type String
        std::cout << "STRING TYPE:" << std::endl;

        IntArray<std::string, length> array1;

        // Fill the array with numbers 1 through 10
        for (int i{ 0 }; i<length; ++i)
            array1[i] = "string";

        // Print out all the numbers
        for (int i{ 0 }; i<array1.getLength(); ++i)
            std::cout << array1[i] << ' ';
        //Copy array
        IntArray<std::string, length> array3;
        array1.copy(array3);

        // Print out all the numbers
        for (int i{ 0 }; i<array3.getLength(); ++i)
            std::cout << array3[i] << ' ';
        std::cout << '\n';

        // Resize the array to 8 elements
        array3.resize(8);

        // Insert the number 20 before element with index 5
        array3.insertBefore("also_string", 5);

        // Remove the element with index 3
        array3.remove(3);

        // Add 30 and 40 to the end and beginning
        array3.insertAtEnd("Hi");
        array3.insertAtBeginning("Boo");

        // Find Element
        std::string value1 = "Hi";
        std:: cout << "idx of element "  << value1 << " = " <<  array3.findElement(value1) << std::endl;

        // Print out all the numbers
        for (int i{ 0 }; i<array3.getLength(); ++i)
            std::cout << array3[i] << ' ';

    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}