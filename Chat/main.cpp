#include "include/Chat.hpp"

void loop(Chat& chat) {

    while (chat.doesChatWork()) {
        chat.showMainMenu();
        while (chat.getCurrentUser()) {
            chat.showChatMenu();
        }
    }
}
// Inspired by "Webinar "Writing a console chat with a mentor"" by SkillFactory
int main()
{
    Chat chat;

    chat.start();
    std::thread l(loop, std::ref(chat));
    l.join();
    return 0;
}