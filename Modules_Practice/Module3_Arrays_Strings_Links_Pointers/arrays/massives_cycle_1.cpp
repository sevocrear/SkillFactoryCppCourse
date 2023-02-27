#include <iostream>
using namespace std;

int main()
{
    int size = 10;
    int array[size];
    cout << "Enter ints" << endl;
    for (int i = 0; i < 10; ++i) {
        cin >> array[i];
    }
     cout << "Entered ints" << endl;
    for (int v:array) {
        cout << v << " " << endl;
    }
}