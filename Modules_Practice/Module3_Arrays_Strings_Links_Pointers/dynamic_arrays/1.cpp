#include <iostream>
using namespace std;

int main()
{
    int *a = new int(10); // Выделяем память для хранения целого числа
    cout << *a << endl;
    *a = 88;          // Записываем значение 88 в динамически выделенную область памяти
    cout << a << endl;        // Печатаем адрес выделенной нам памяти 0xf3f2cc
    cout << *a << endl;       // Печатаем значение находящееся в участке памяти, 88.
    delete a;         // Освобождаем память после того как с ней поработали.
    return 0;
}