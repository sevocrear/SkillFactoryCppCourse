#include <iostream>

using namespace std;
int sum(int n)
{   
    if (n != 0) {
        n += sum(n - 1);
    }
    return n;
}

int main() {
    int n = 0;
    n = sum(1);
    cout << n << endl;
    return 0;
}