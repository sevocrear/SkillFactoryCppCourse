#include "chat.hpp"
#include "iostream"
#include "string.h"

Chat::Chat() {
    data_count = 0;
}
void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    // Ваш код
    uint* hash = sha1(_pass, pass_length);
    AuthData log_pass(_login, hash);
    data[data_count++] = log_pass;
    std::cout << "1 " << hash << std::endl;
}
bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    // Ваш код
    // Нужно вернуть true в случае успешного логина
    uint* hash = sha1(_pass, pass_length);

    for (int idx = 0; idx < data_count; idx ++) {
        if (strcmp(_login, data[idx].login) == 0) {
            if (*hash == *data[idx].pass_sha1_hash) return true;
        }
    }
    return false;
}