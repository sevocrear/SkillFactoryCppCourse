#include <iostream>
#include "include/Stack.hpp"
#include <string>
bool BracketsBalanced(string expr)
{
    // ваш код
    Stack stack = Stack();
    for (auto &c : expr)
    {
        if (c == '{' || c == '(' || c == '[')
            stack.push(1);
        else {
            int prev_c = stack.pop();
            if (!prev_c) {
                return false;
            }
        }
    }
    if (!stack.isEmpty()) {
        return false;
    }
    return true;
}

int main()
{
    std::string expr = "[(])";
    std::cout << BracketsBalanced(expr) << std::endl;
    return 0;
}