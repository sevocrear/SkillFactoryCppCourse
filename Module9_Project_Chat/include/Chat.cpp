#include "Chat.hpp"

void Chat::start()
{
    doesChatWork_ = true;
}

std::shared_ptr<User> Chat::getUserByLogin(const std::string &login)
{
    /// @brief Finds user with given login if exists
    /// @param login
    /// @return std::shared_ptr<User> user
    std::shared_ptr<User> current_user = nullptr;
    for (auto &user : users_)
    {
        if (login == user.getUserLogin())
        {
            current_user = std::make_shared<User>(user);
        }
    }
    return current_user;
}

void Chat::login()
{
    /// @brief Logins into the chat by given log-pass
    std::string login, password;
    char operation;
    while (!currentUser_)
    {
        std::cout << "\x1B[34mlogin:\033[0m\t\t" << std::endl;
        std::cin >> login;

        std::cout << "\x1B[34mpassword:\033[0m\t\t" << std::endl;
        std::cin >> password;

        currentUser_ = getUserByLogin(login);

        if (currentUser_ == nullptr || (password != currentUser_->getUserPassword()))
        {
            currentUser_ = nullptr; // if password is wrong, reset current user

            std::cout << "\x1B[31mlogin failed... Check login and password...\033[0m\t\t" << std::endl;

            std::cout << "\x1B[34m(0) Repeat login\033[0m\t\t" << std::endl;
            std::cout << "\x1B[34m(1) Exit\033[0m\t\t" << std::endl;

            std::cin >> operation;
            if (operation == '1')
            {
                break;
            }
        }
    }
    std::cout << "\x1B[32mLogin Successful!\033[0m\t\t" << std::endl;
}

bool Chat::doesAliasExist(std::string &alias)
{
    /// @brief Checks if user with @alias exists.
    /// @param alias - user's alias
    /// @return boolean. True is exists
    for (auto &user : users_)
    {
        if (alias == user.getUserAlias())
        {
            return true;
        }
    }
    return false;
}
void Chat::sign_up()
{
    /// @brief Signs up with given login, pass and name. Same logins aren't possible
    std::string login, password, alias, name;

    std::cout << "\x1B[34mlogin (should be unique, private):\033[0m\t\t" << std::endl;
    std::cin >> login;

    std::cout << "\x1B[34mpassword:\033[0m\t\t" << std::endl;
    std::cin >> password;

    std::cout << "\x1B[34malias (should be unique, public):\033[0m\t\t" << std::endl;
    std::cin >> alias;

    std::cout << "\x1B[34mname:\033[0m\t\t" << std::endl;

    std::cin.ignore();
    std::getline(std::cin, name);

    if (getUserByLogin(login))
    {
        // throw UserLoginExp();
        std::cout << "\x1B[31m login is busy, choose another one\033[0m\t\t" << std::endl;
        sign_up();
    }

    if (doesAliasExist(alias) || alias == "all")
    {
        // throw UserLoginExp();
        std::cout << "\x1B[31m alias is busy,  it should be unique. Choose another one\033[0m\t\t" << std::endl;
        sign_up();
    }

    User user = User(login, password, alias, name);
    users_.push_back(user);
    currentUser_ = std::make_shared<User>(user);
    std::cout << "\x1B[32mRegistration Successful!\033[0m\t\t" << std::endl;
}

void Chat::showMainMenu()
{
    /// @brief Show Main Menu of the chat
    char operation;
    currentUser_ = nullptr;

    while (doesChatWork() && !currentUser_)
    { // While chat works and user is not selected
        std::cout << "\x1B[37mMain Menu\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(0) Register\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(1) Login\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(2) Quit\033[0m\t\t" << std::endl;

        std::cin >> operation;
        switch (operation)
        {
        case '0': // Register
            sign_up();
            break;
        case '1': // Login
            login();
            break;
        case '2':
            doesChatWork_ = false;
            break;
        default:
            std::cout << "\x1B[31mTry again...\033[0m\t\t" << std::endl;
            break;
        }
    }
}

void Chat::write_message()
{
    /// @brief Write message and send it to someone by @alias
    std::string to, text;

    std::cout << "\x1B[36mTo (alias or all):\033[0m\t\t" << std::endl;
    std::cin >> to;
    
    std::cout << "\x1B[36mText:\033[0m\t\t" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, text);

    if (doesAliasExist(to) || to == "all") {
        messages_.push_back(Message(currentUser_->getUserAlias(), to, text));
        std::cout << "\x1B[32mMessage sent!\033[0m\t\t" << std::endl;
    }
    else {
        std::cout << "\x1B[31merror sensing message. Can't find user by given alias\033[0m\t\t" << std::endl;
        return;
    }
}

void Chat::read_messages() {
    std::cout << "\x1B[90m\nStart of the Chat\n\033[0m\t\t" << std::endl;

    for (auto &message : messages_) {
        if (message.getTo() == currentUser_->getUserAlias() || message.getTo() == "all") {
            if (message.getFrom() == currentUser_->getUserAlias()) {
                std::cout << "\x1B[36mFrom:" << message.getFrom() << " (me)\033[0m\t\t" << std::endl;
            }
            else {
                std::cout << "\x1B[36mFrom:" << message.getFrom() << "\033[0m\t\t" << std::endl;
            }
            std::cout << "\x1B[97m" << message.getText() << "\033[0m\t\t" << std::endl;
        }
    }
    std::cout << "\x1B[90m\nEnd of the Chat\n\033[0m\t\t" << std::endl;
}
void Chat::showChatMenu()
{
    /// @brief Shows Chan Menu to send, read messages and log out
    char operation;

    while (doesChatWork() && currentUser_)
    { // While chat works and user didn't log out
        std::cout << "\x1B[37mChat Menu\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(0) Send Message\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(1) Read Messages\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(2) Log out\033[0m\t\t" << std::endl;

        std::cin >> operation;
        switch (operation)
        {
        case '0': // Send Message
            write_message();
            break;
        case '1': // Read Messages
            read_messages();
            break;
        case '2': // Log out
            currentUser_ = nullptr;
            break;
        default:
            std::cout << "\x1B[31mTry again...\033[0m\t\t" << std::endl;
            break;
        }
    }
}
