//Напишите программу, которая определяет, является ли число степенью двойки, на примере числа 8:
#include <iostream>
using namespace std;
int main() 
{
    int x;
    cout << "Enter the integer" << endl;
    cin >> x;

    bool power0f2;
    power0f2 = (x-1) & x;
    cout << "Ответ: " << power0f2 << endl <<
         "(если ответ равен 0, то число является степенью двойки, если 1 - не является)" << endl;
    return 0;
}