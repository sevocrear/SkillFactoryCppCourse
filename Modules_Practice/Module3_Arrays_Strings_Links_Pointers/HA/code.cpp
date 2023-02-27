//Реализуйте шифр Цезаря для следующего преобразования текста: каждая буква исходного текста заменяется буквой, стоящей на  символов впереди неё. Будем полагать что алфавит зацикленный, т.е. после буквы  идет буква .

// Ваша программа должна будет уметь в зависимости от выбора пользователя зашифровать или дешифровать (т.е. восстановить исходный) текст, введённый с консоли, заменяя согласно шифру Цезаря строчные символы на строчные, заглавные на заглавные.

// Входные данные: символ выбора операции (шифрование или дешифрование), длина строки, массив символов char arr[], целое число  — сдвиг шифра. Вводится строка без каких-либо неалфавитных символов.
// Символы в строке:  (строчные и заглавные).
// Неалфавитные символы: знаки препинания, пробелы, цифры, — не вводятся и, соответственно, не меняются.
// Выходные данные: преобразованная согласно шифру строка.

// Дополнительно в этой задаче вы можете с помощью цикла while поддержать повтор введения строки с возможностью закрыть программу, если вместо оператора введен иной заданный символ,  а также дешифрование текста.

#include <iostream>

using namespace std;

int main()
{
    char op_type;
    int size, shift;

    while (true)
    {
        cout << "Choose type of operation: ('e' - encode, 'd' - decode). Or enter 'q' - to quit" << endl;
        cin >> op_type;

        if (op_type == 'q') // if q is pressed the program breaks
            break;
        else if ((op_type != 'e') && (op_type != 'd'))
        {
            cout << "Ops..You entered wrong character of operation type before" << endl;
            continue;
        }

        // String Size Input
        cout << "Enter size of the string:" << endl;
        cin >> size;

        // Dynamic Array Init
        char *array = new char[size];

        // Fill in the array
        cout << "Enter your string elements" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }

        // Input a shift
        cout << "Enter a shift:" << endl;
        cin >> shift;

        // Choose btw operations
        switch (op_type)
        {
        case 'e': // encode
            cout << "you chose to encode!" << endl;
            for (int i = 0; i < size; i++)
            {
                // Lowercase
                if ((array[i] >= 'a') && (array[i] <= 'z' - shift))
                {
                    array[i] += shift;
                }
                else if ((array[i] > 'z' - shift) && (array[i] <= 'z'))
                {
                    array[i] = 'a' + shift - ('z' - array[i]) - 1;
                }
                // Uppercase
                if ((array[i] >= 'A') && (array[i] <= 'Z' - shift))
                {
                    array[i] += shift;
                }
                else if ((array[i] > 'Z' - shift) && (array[i] <= 'Z'))
                {
                    array[i] = 'A' + shift - ('Z' - array[i]) - 1;
                }
            }

            break;
        case 'd': // decode
            cout << "you chose to decode!" << endl;

            for (int i = 0; i < size; i++)
            {
                // Lowercase
                if ((array[i] >= 'a'+shift) && (array[i] <= 'z'))
                {
                    array[i] -= shift;
                }
                else if ((array[i] >= 'a') && (array[i] <='a'+shift))
                {
                    array[i] = array[i] - 'a' - shift + 'z' + 1 ;
                }
                // Uppercase
                if ((array[i] >= 'A'+shift) && (array[i] <= 'Z'))
                {
                    array[i] -= shift;
                }
                else if ((array[i] >= 'A') && (array[i] <='A'+shift))
                {
                    array[i] = array[i] - 'A' - shift + 'Z' + 1 ;
                }
            }
            break;
        }
        cout << array << endl;
        delete[] array; // Правильное освобождение памяти динамического массива
    }
}