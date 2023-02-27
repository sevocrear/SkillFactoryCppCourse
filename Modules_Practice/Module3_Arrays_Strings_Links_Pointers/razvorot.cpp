#include <iostream>
using namespace std;

int main()
{
    int size = 5;
    int *a = new int[size];

    for (int i = 0; i < size; ++i)
    {
        cin >> a[i]; //Считываем элементы массива в цикле
    }
    for (int i = 0; i < size / 2; i++)
    {
        int n = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = n;
    }

    for (int i = 0; i < size; ++i)
    {
        cout << a[i]; // Печатаем что получилось
    }
    delete[] a;
    return 0;
}