#include <iostream>
using namespace std;

//Перепишите свою программу «Калькулятор», используя функции для каждой операции, а функции вычисления факториала и возведения в степень перепишите рекурсивно.

void input_a_b(int *a, int *b)
{
    /// @brief Method to input ints a and b from terminal
    /// @param a - 1st integer number (input)
    /// @param b - 2nd integer number (input)
    cout << "Enter integer numbers (a) and (b). Put a space btw them:" << endl;
    cin >> *a >> *b;
}

void input_a(int *a)
{
    /// @brief Method to input int a from terminal
    /// @param a - integer number (input)
    cout << "Enter integer number (a):" << endl;
    cin >> *a;
}

void output(const int *a, const int *b, const float *result, char sign, int num_of_ints = 2)
{
    /// @brief Output function. It outputs (prints) the result of operation.
    /// @param a - 1st integer number (input)
    /// @param b - 2nd integer number (input)
    /// @param result - results (float)
    /// @param sign - char operator
    /// @param num_of_ints - number of inputs
    if (num_of_ints == 2)
    {
        cout << *a << " " << sign << " " << *b << " = " << *result << endl;
    }
    else if (num_of_ints == 1)
    {
        cout << *a << " " << sign << " = " << *result << endl;
    }
    else
    {
        cout << "no function for " << num_of_ints << "operands" << endl;
    }
}
void sum(int a, int b, float *result)
{
    /// @brief Inplace sum func (a + b)
    /// @param a - 1st integer number (input)
    /// @param b - 2nd integer number (input)
    /// @param result - results (float)
    *result = a + b;
}

void sub(int a, int b, float *result)
{
    /// @brief Inplace substruct func (a - b)
    /// @param a - 1st integer number (input)
    /// @param b - 2nd integer number (input)
    /// @param result - results (float)
    *result = a - b;
}

void mul(int a, int b, float *result)
{
    /// @brief Inplace multiplication func
    /// @param a - 1st integer number (input)
    /// @param b - 2nd integer number (input)
    /// @param result - results (float)
    *result = a * b;
}

void div(int a, int b, float *result)
{
    /// @brief Inplace division func (a / b)
    /// @param a - 1st integer number (input)
    /// @param b - 2nd integer number (input)
    /// @param result - results (float)
    if (b != 0)
    {
        *result = (float)a / b;
        cout << a << " "
             << "/"
             << " " << b << " = " << *result << endl;
    }
    else
    {
        cout << "Impossible to divide. (b) is equal to zero..." << endl;
    }
}

void invol(int a, int b, float *result)
{
    /// @brief Inplace power func (a**b)
    /// @param a - 1st integer number (input)
    /// @param b - 2nd integer number (input)
    /// @param result - results (float)
    if (b != 0)
    {
        *result *= a;
        b--;
        invol(a, b, result);
    }
}

void factorial(int a, float *result)
{
    /// @brief Inplace factorial func (a!)
    /// @param a - 1st integer number (input)
    /// @param result - results (float)
    if (a != 0)
    {
        *result *= a;
        a--;
        factorial(a, result);
    }
}

void show_help()
{
    /// @brief  @brief Helping message func
    cout << "The supported operations:" << endl;
    cout << "'+' - addition" << endl;
    cout << "'-' - subtraction" << endl;
    cout << "'*' - multiplication" << endl;
    cout << "'/' - division" << endl;
    cout << "'p' - involution" << endl;
    cout << "'!' - factorial" << endl;
}

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
            show_help();
            continue;
        }
        if (sign == '!') {
            input_a(&a);
        }
        else {
            input_a_b(&a, &b);
        }
        switch (sign)
        {
        case '+':
            sum(a, b, &result);
            output(&a, &b, &result, sign, 2);
            break;
        case '-':
            sub(a, b, &result);
            output(&a, &b, &result, sign, 2);
            break;
        case '*':
            mul(a, b, &result);
            output(&a, &b, &result, sign, 2);
            break;
        case '/':
            div(a, b, &result);
            break;
        case 'p':
            result = 1;
            invol(a, b, &result);
            output(&a, &b, &result, sign, 2);
            break;
        case '!':
            result = 1;
            factorial(a, &result);
            output(&a, &b, &result, sign, 1);
            break;
        default:
            cout << "Interesting symbol... Let's try again" << endl;
            break;
        }
    }
}