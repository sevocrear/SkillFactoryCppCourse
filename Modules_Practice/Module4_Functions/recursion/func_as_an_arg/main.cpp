#include <iostream>
using namespace std;

bool ascending(int a, int b)
{
    return a > b;
}

bool descending(int a, int b)
{
    return a < b;
}

void bubbleSort(int arr[], int n, bool (*compare)(int,int))  
{  
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if ((*compare)(arr[j],arr[j+1]))
            {
            	arr[j] ^= arr[j+1];
            	arr[j+1] ^= arr[j];
                arr[j] ^= arr[j+1];
            }
        }
    }
}  

int main()
{
    int arr[10] = {5,7,35,2,81,1,16,8,9,14};
    
    bool ascend = false;
    cout << "Sort type:";
    cin >> ascend;
    bool (*sorter)(int,int) = ascend ? ascending : descending;
    bubbleSort(arr, 10, sorter);
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;    
}