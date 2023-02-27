//программа (простейший консольный калькулятор), которая принимает от пользователя два
//целых числа и поочередно выводит результаты простейших математических (сложение,
//вычитание, умножение, деление) и битовых операций (И, ИЛИ, исключающее ИЛИ) для этих
//чисел.
#include <iostream>
using namespace std;
int main()
{
	int a;
	int b;
	int sumres, subres, mulres, andres, orres, xorres;
	float divres;
	cout << "Введите два числа:" << endl;
	cin >> a >> b;

	sumres = a + b;
	subres = a - b;
	mulres = a * b;
	divres = (float)a / b;
	andres = a & b;
	orres = a | b;
	xorres = a ^ b;
	cout << "Результаты математических и логических операций:" << endl;
	cout << a << " + " << b << " = " << sumres << endl;
	cout << a << " - " << b << " = " << subres << endl;
	cout << a << " * " << b << " = " << mulres << endl;
	cout << a << " / " << b << " = " << divres << endl;
	cout << a << " & " << b << " = " << andres << endl;
	cout << a << " | " << b << " = " << orres << endl;
	cout << a << " ^ " << b << " = " << xorres << endl;
	return 0;
}