#include <iostream>
using namespace std;

int sumArray(int* a, int size)
{
    int sum = 0;
    a[0] = 5;
    for (int i = 0; i < size; ++i)
    {
        sum += a[i];
    }

    return sum;
}

int main()
{
    int array[5] = {0,1,2,3,4};

    int sum = sumArray(array, 5);

    cout << sum << endl;
    cout << array[0]<< endl;

    return 0;
}