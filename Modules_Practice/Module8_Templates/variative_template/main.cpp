#include <iostream>
using namespace std;

// Определение функции с нулевым числом параметров для выхода из рекурсии
void show() { }

// Определение функции с одним (последним) параметром
template <typename T> void show(T value) {
    cout << value << endl << endl;
}

// Определение функции для одного и более параметров
template<typename T, typename ... Args>
void show(T value, Args ... args) 
{
    cout << value << ", ";
    show(args ...);
}

int main() 
{
    int a = 5;
    double b = 3.14;
    char c = 'H';
    string d = "variadic templates";
    long e = 12345L;

    show(a, b, c, d);
    show(d, b);
    show(e);

    return 0;
}