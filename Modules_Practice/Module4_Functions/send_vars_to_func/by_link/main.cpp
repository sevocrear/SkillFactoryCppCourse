#include <iostream>
using namespace std;

void AddTwo(int& a)
{
    a += 2;
}

int main()
{
    int num = 8;

    AddTwo(num);

    cout << num << endl; // num = 10

    return 0;
}
