#include <iostream>
using namespace std;

int main () {
    int *a = new int[10];
    a[0] = 10;
    a[1] = 20;
    
    cout << a[2];
    delete[] a;
    return 0;
}