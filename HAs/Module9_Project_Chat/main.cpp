#include "include/Chat.hpp"
#include "include/hash_table.hpp"
// Inspired by "Webinar "Writing a console chat with a mentor"" by SkillFactory
// int main()
// {
//     Chat chat;

//     chat.start();

//     while (chat.doesChatWork()) {
//         chat.showMainMenu();
//         while (chat.getCurrentUser()) {
//             chat.showChatMenu();
//         }
//     }
//     return 0;
// }
int main()
{
    HashTable table;
    table.add("admin", "pass");
    std::cout << table.find("admin") << std::endl;
}