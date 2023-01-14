#include "Chat.hpp"

void Chat::start() {
    doesChatWork_ = true;
}

std::shared_ptr<User> Chat::getUserByLogin(const std::string& login) {
    /// @brief Finds user with given login if exists
    /// @param login 
    /// @return std::shared_ptr<User> user
    std::shared_ptr<User> current_user = nullptr;
    for (auto &user: users_) {
        if (login == user.getUserLogin()) {
            current_user = std::make_shared<User>(user);
        }
    }
    return current_user;
}

void Chat::login() {
    /// @brief Logins into the chat by given log-pass
    std::string login, password;
    char operation;
    while (!currentUser_) {
        std::cout << "\x1B[34mlogin:\033[0m\t\t" << std::endl; 
        std::cin >> login;

        std::cout << "\x1B[34mpassword:\033[0m\t\t" << std::endl; 
        std::cin >> password;

        currentUser_ = getUserByLogin(login);

        if (currentUser_ == nullptr || (password != currentUser_->getUserPassword())) {
            currentUser_ = nullptr; // if password is wrong, reset current user

            std::cout << "\x1B[31mlogin failed... Check login and password...\033[0m\t\t" << std::endl;

            std::cout << "\x1B[34m(0) Repeat login\033[0m\t\t" << std::endl; 
            std::cout << "\x1B[34m(1) Exit\033[0m\t\t" << std::endl; 

            std::cin >> operation;
            if (operation == '1') {
                break;
            }
        }
    }


}

void Chat::sign_up() {
    /// @brief Signs up with given login, pass and name. Same logins aren't possible
    std::string login, password, name;

    std::cout << "\x1B[34mlogin:\033[0m\t\t" << std::endl; 
    std::cin >> login;

    std::cout << "\x1B[34mpassword:\033[0m\t\t" << std::endl; 
    std::cin >> password;

    std::cout << "\x1B[34mname:\033[0m\t\t" << std::endl; 
    std::cin >> name;

    if (getUserByLogin(login) || login == "all") {
        // throw UserLoginExp();
        std::cout << "\x1B[31m login is busy, choose another one\033[0m\t\t" << std::endl;
        sign_up();
    }

    User user = User(login, password, name);
    users_.push_back(user);
    currentUser_ = std::make_shared<User>(user);
}

void Chat::showMainMenu() {
    /// @brief Show Main Menu of the chat
    char operation;
    currentUser_ = nullptr;

    while (doesChatWork() && !currentUser_) { // While chat works and user is not selected
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

void Chat::showChatMenu() {
    char operation;

    while (doesChatWork() && currentUser_) { // While chat works and user didn't log out
        std::cout << "\x1B[37mChat Menu\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(0) Send Message\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(1) Read Messages\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(2) Log out\033[0m\t\t" << std::endl;

        std::cin >> operation;
        switch (operation)
        {
        case '0': // Send Message
            
            break;
        case '1': // Read Messages
            
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