#include "include/Chat.hpp"
// #include "Chat.hpp" // for cmakeLists

// Inspired by "Webinar "Writing a console chat with a mentor"" by SkillFactory
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