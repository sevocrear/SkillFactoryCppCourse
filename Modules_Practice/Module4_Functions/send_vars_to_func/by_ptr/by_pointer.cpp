#include <iostream>
using namespace std;

void bar(int* a)
{
    *a = 5;
}

int main()
{
    int x = 6;
    bar(&x); // передаем указатель на переменную с помощью операции взятия адреса

    int* y = new int(1);
    bar(y); // передаем указатель на переменную y
    cout << x << endl;
    cout << *y << endl;
    delete y;

    return 0;
}