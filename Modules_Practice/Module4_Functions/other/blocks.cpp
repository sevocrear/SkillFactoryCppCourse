#include <iostream>
using namespace std;

int main()
{
    int c = 3;
    if (c == 3) {
        int a = 1;
        a = 3;
    }
    a = 5; // error переменная а уже не в области видимости
}