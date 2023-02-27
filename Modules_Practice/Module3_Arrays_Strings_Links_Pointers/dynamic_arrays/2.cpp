#include <iostream>
using namespace std;
int main()
{
    int *ptr = nullptr;
    ptr = new int(10);
    cout << *ptr;
    delete ptr;
    return 0;
}