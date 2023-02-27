// Напишите программу, которая считает сумму чисел от 1 до 100, но останавливается, когда сумма станет больше 1000 и выводит полученную сумму.

#include <iostream>
using namespace std;

int main()
{
    int sum = 0;

    for (int i = 1; i <= 100; i++)
    {
        sum += i;
        if (sum > 1000)
        {
            break;
        }
    }
    cout << sum << endl;

    return 0;
}