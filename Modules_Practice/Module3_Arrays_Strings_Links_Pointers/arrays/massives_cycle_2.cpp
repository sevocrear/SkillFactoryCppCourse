#include <iostream>
using namespace std;
int main()
{
    int arr[] = {5, 4, 3, 4, 9};
    int arrayLength = sizeof(arr) / sizeof(arr[0]);
    int minimum = arr[0];
    int maximum = arr[0];
    for (int i = 0; i < arrayLength; ++i)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
        if (arr[i] < minimum)
        {
            minimum = arr[i];
        }
    }
    cout << maximum - minimum << endl;

    return 0;
}