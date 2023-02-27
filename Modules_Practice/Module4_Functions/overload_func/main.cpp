#include <iostream>
using namespace std;

int AbsoluteValue(int num)
{
    if (num < 0)
    {
        num = -num;
    }

    return num;
}

float AbsoluteValue(float num)
{
    if (num < 0)
    {
        num = -num;
    }

    return num;
}


int main()
{
    int a = -7;
    float b = -4.5;

    cout << AbsoluteValue(a) << endl; // вызов int AbsoluteValue(int num)

    cout << AbsoluteValue(b) << endl; // вызов int float AbsoluteValue(float num)

    return 0;
}