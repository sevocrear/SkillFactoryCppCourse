#include "include/Chat.hpp"

void loop() {
    Chat chat;

    chat.start();

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
    std::thread l(loop);
    l.join();
    return 0;
}