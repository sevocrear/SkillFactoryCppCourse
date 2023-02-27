#include <iostream>
using namespace std;

int main() 
{
    int a = 5;
    int b = 4;
    cout << "Before swap:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

    cout << "After swap:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}