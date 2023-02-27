#include <iostream>
using namespace std;

int Add(int a, int b)
{
    int sum;
    sum = a + b;
    return sum;
}

int main()
{
    int x = 3;
    int y = 6;
    int result = Add(x, y); // вызов функции с аргументами 3 и 6
    cout << result << endl;

    return 0;
}