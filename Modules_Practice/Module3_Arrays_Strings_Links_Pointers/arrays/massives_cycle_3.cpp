#include <iostream>
using namespace std;

// Дан массив int arr[] = {5, 4, 3, 4, 9};

//Найдите позицию максимального элемента массива.
int main()
{
    int arr[] = {5, 4, 3, 4, 9};
    int arrayLength = sizeof(arr) / sizeof(arr[0]);
    int maximum = arr[0];
    int max_id = 0;
    for (int i = 0; i < arrayLength; ++i)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
            max_id = i;
        }
    }
     cout << "index = " << max_id << endl << "maximum = " << maximum << endl;

    return 0;
}