#include <iostream>
using namespace std;

float harmonic_mean(float arr[], int size)
{
    if (size == 0)
    {
        throw "zero array";
    }
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0.0)
        {
            throw "element zero in array";
        }
        sum = sum + 1.0 / arr[i];     
   }

    if (sum < 0.0001 && sum > -0.0001)
    {
        throw "zero sum of elements";
    }
    return size/sum;
}

int main()
{
    float array1[2] = {0.0, 0.0};
    float array2[2] = {1.5, -1.5};
    float array3[2] = {2.3, 0.5};
    float hmean;
    
    try 
    {
        hmean = harmonic_mean(array1, 2);
        cout << "hmean = " << hmean << endl;
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
    
    try 
    {
        hmean = harmonic_mean(array2, 2);
        cout << "hmean = " << hmean << endl;
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
    
    try 
    {
        hmean = harmonic_mean(array2, 0);
        cout << "hmean = " << hmean << endl;
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
    
    try 
    {
        hmean = harmonic_mean(array3, 2);
        cout << "hmean = " << hmean << endl;
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
    
    return 0;
}