#include <iostream>
using namespace std;

void changePointer(int** p, int* val)
{
    *p = val;
}

int main()
{
    int a = 6;
    int* pa = &a;

    int b = 9;
    changePointer(&pa,&b);
    cout << a << endl; // значение a не изменилось
    cout << *pa; // pa указывает на b - будет выведено 9

    return 0;
}

