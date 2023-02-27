#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    int factorial = 1;

    int i = 1;
    while (i < n)
    {
        factorial *= ++i;
    }

    cout << "Факториал числа 10 = " << factorial << endl;

    return 0;
}