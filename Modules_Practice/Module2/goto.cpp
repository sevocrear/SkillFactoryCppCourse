// ради практики, напишите программу, которая выводит числа от 0 до 9 в столбик с помощью оператора goto.
#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    
    vivod:
        cout << a << endl;
    if (a < 9) {
        a++;
        goto vivod;
    }

    return 0;
}