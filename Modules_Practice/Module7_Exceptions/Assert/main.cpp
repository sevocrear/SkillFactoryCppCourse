#include <iostream>
#include <assert.h>

using namespace std;

float harmonic_mean(float arr[], int size)
{
   assert(size && "Array size 0!");
   float sum = 0;
   for (int i = 0; i < size; i++)
   {
        assert( (arr[i] >  0.0001 || arr[i] < -0.0001) && "Array element 0!");
        sum = sum + 1.0 / arr[i];     
   }

   assert((sum > 0.0001 || sum < -0.0001) && "The sum of the array elements is 0!");
   return size/sum;
}

int main()
{
    float arr[6] = {5,4,3,0,1,2};
    int c = harmonic_mean(arr, 5);
    cout << "harmonic_mean result: " << c << endl;

    return 0;
}