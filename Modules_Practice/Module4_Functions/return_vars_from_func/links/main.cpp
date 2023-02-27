#include <iostream>
using namespace std;

int elements[] = {1,2,3,4,5};

int& GetElement(int i)
{	
    return elements[i];
}

int main()
{ 
    for (int i = 0; i < 5; ++i) 
    { 
        cout << elements[i] << endl; 
    } 

    int& element = GetElement(1); 
    element = 11; 
    for (int i = 0; i < 5; ++i) 
    { 
        cout << elements[i]; 
    } 

    return 0; 
}