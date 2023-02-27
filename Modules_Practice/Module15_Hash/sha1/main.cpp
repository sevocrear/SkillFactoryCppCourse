#include <iostream>
#include "include/chat.hpp"
using namespace std;
int main() 
{   
    Chat chat;
    char login[] = "ilia";
    char pass[] = "qwerty3215";

    chat.reg(login, pass, sizeof(pass) - 1);
    cout << chat.login(login, pass, sizeof(pass) - 1) << endl;
    return 0;
}