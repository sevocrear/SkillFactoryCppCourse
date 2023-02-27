#include <iostream>
#include <exception>
using namespace std;

/**
Перепишите класс исключения BadHarmonicMean так, чтобы он наследовался от класса exception. Виртуальный метод what() должен выводить строку "Harmonic mean exception". Протестируйте результат подобно заданию 7.4.1
**/
class BadHarmonicMean : public exception
{
public:
    virtual const char* what() const noexcept override  {return "Harmonic mean exception ";}
};

float harmonic_mean(float arr[], int size)
{
    if (size == 0)
    {
        throw BadHarmonicMean();
    }
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0.0)
        {
            throw BadHarmonicMean();
        }
        sum = sum + 1.0 / arr[i];     
    }

    if (sum < 0.0001 && sum > -0.0001)
    {
        throw BadHarmonicMean();
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
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    
    try 
    {
        hmean = harmonic_mean(array2, 2);
        cout << "hmean = " << hmean << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    
    try 
    {
        hmean = harmonic_mean(array2, 0);
        cout << "hmean = " << hmean << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    
    try 
    {
        hmean = harmonic_mean(array3, 2);
        cout << "hmean = " << hmean << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    
    return 0;
}