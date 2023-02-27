#include <iostream>
using namespace std;

int main()
{
    // Объявляем переменную value равную 88
    int value = 88;
    // Объявляем ссылку на value или псевдоним
    // value и valueRef будут хранить одинаковые значения
    int &valueRef = value;

    // Напечатается 88
    cout << value << endl;
    // Также напечатается 88, т.к valueRef является ссылкой на value (псевдонимом value)
    cout << valueRef << endl;

    // Изменяем значение valueRef
    valueRef = 99;
    // Напечатается 99
    cout << valueRef << endl;
    // Также напечатается 99, значение value изменится, когда меняем valueRef
    cout << value << endl;

    // Изменяем значение value
    value = 55;
    // Напечатается 55
    cout << value << endl;
    // Также напечатается 55, значение valueRef изменится, когда меняем value
    cout << valueRef << endl;
    return 0;
}