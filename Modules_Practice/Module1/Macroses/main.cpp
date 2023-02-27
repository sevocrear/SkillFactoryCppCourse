#include <iostream>
using namespace std;
#define cubeof(X) X*X*X
int main()
{
	float x;
	cin >> x;
	float y = cubeof(x);
	cout << "Куб числа "<< x << " = " << y<<endl; // вывод Hello World на консоль
	return 0;
}