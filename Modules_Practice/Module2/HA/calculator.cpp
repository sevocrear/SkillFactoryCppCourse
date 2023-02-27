#include <iostream>
using namespace std;

//В качестве домашнего задания ко второму модулю мы предлагаем вам написать интерактивный калькулятор,
// который запрашивает у пользователя на выбор математическую операцию (операторы: + - * / ! ^) и целые числа,
//  с которыми нужно выполнить эту операцию. Программа должна выводить результат выполнения выбранной математической операции.

// Подсказка: Не забудьте исключить случай деления на ноль, а также используйте операции вычисления факториала и возведения в степень,
// которые вы уже реализовали в этом модуле. Для решения задания идеально подходит оператор switch.

int main()
{
    char sign;    // operation sign
    int a, b;     // operands
    float result; // result of the operation

    while (true)
    {
        cout << "Enter mathematical operation symbol: ('q' to exit the program, 'h' for help)" << endl;
        cin >> sign;
        if (sign == 'q') // if q is pressed the program breaks
            break;
        if (sign == 'h')
        { // if q is pressed the program breaks
            cout << "The supported operations:" << endl;
            cout << "'+' - addition" << endl;
            cout << "'-' - subtraction" << endl;
            cout << "'*' - multiplication" << endl;
            cout << "'/' - division" << endl;
            cout << "'p' - involution" << endl;
            cout << "'!' - factorial" << endl;
            continue;
        }

        switch (sign)
        {
        case 'q':
            break;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case 'p':
            cout << "Enter integer numbers (a) and (b). Put a space btw them:" << endl;
            cin >> a >> b;

            if (sign == '+')
            {
                result = a + b;
            }
            else if (sign == '-')
            {
                result = a - b;
            }
            else if (sign == '*')
            {
                result = a * b;
            }
            else if (sign == '/')
            {
                if (b != 0)
                {
                    result = (float)a / b;
                }
                else
                {
                    cout << "Impossible to divide. (b) is equal to zero..." << endl;
                }
            }
            else
            { // p (a power b)
                result = 1;
                for (int i = 0; i < b; i++)
                {
                    result *= a;
                }
            }
            // Print the result
            cout << a << " " << sign << " " << b << " = " << result << endl;
            break;

        case '!':
            cout << "Enter an integer number (a):" << endl;
            cin >> a;

            result = 1;
            for (int i = 1; i <= a; i++)
            {
                result *= i;
            }
            
            // Print the result
            cout << a << " " << sign << " = " << result << endl;
            break;

        default:
            cout << "Interesting symbol... Let's try again" << endl;
            break;
        }
    }
}