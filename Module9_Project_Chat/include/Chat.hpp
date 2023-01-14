#pragma once
#include <vector>
#include <memory>
#include "User.hpp"
#include "Message.hpp"
#include <iostream>

struct UserLoginExp: public std::exception {
    const char *what() const noexcept override {return "ERROR: user login is busy";}
};

class Chat{
    private:
        std::shared_ptr<User> currentUser_ = nullptr;

        bool doesChatWork_ = false;

        std::vector<User> users_;
        std::vector<Message> messages_;

        void login();
        void sign_up();
        // void showChat() const;
        // void showAllUsersNames() const;
        // void writeMessage();

    public:
        void start();
        bool doesChatWork() const {return doesChatWork_;}
        void showMainMenu();
        void showChatMenu();
        std::shared_ptr<User> getCurrentUser() const {return currentUser_;}
        std::shared_ptr<User> getUserByLogin(const std::string& login);
        
};