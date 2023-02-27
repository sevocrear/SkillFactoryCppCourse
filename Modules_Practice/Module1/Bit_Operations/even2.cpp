//определение, является ли число чётным.
#include <iostream>
using namespace std;
int main() 
{
    int x;
    cout << "Enter the integer" << endl;
    cin >> x;

    bool ifeven;
    ifeven = x & 1;
    cout << "Ответ: " << ifeven << endl <<
         "(если ответ равен 0, то число четное, если 1 - нечетное)" << endl;
    return 0;
}