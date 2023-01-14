#include "include/Chat.hpp"

int main()
{
    Chat chat;

    chat.start();

    while (chat.doesChatWork()) {
        chat.showMainMenu();
        while (chat.getCurrentUser()) {
            chat.showChatMenu();
        }
    }
    return 0;
}