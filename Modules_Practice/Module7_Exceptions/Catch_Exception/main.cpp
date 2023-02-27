#include <iostream>
using namespace std;


int Divide(int a, int b)
{
	if (b == 0)
	{
	    throw "division by zero";
	}
	
	return a / b;
}

int main()
{
	int a = 3;
	int b = 0;

	try
	{		
		cout << Divide(a,b) << endl;
        std::cout << "Will it be printed?" << std::endl;
	}
	catch(const char* exception)
	{
		cout << "Exception: " << exception << endl;
	}

      cout << "Program end!" << endl;

	return 0;
}