#pragma once
#include <vector>
#include <memory>
#include "User.hpp"
#include "Message.hpp"
#include <iostream>
#include <unordered_map>
#include <string>
#include <filesystem>
#include <algorithm>

struct UserLoginExp: public std::exception {
    const char *what() const noexcept override {return "ERROR: user login is busy";}
};

class Chat{
    private:
        std::shared_ptr<User> currentUser_ = nullptr;

        bool doesChatWork_ = false;

        std::vector<User> users_;
        std::vector<Message> messages_;
        std::unordered_map<std::string, std::string> hash_table_;

        void log_in();
        void sign_up();
        // void showChat() const;
        // void showAllUsersNames() const;
        void write_message();
        void read_messages();

        int hash_func(const std::string& login, int offset);
    public:
        void start();
        void readUsersInfo();
        void readMessagesInfo();
        std::fstream openFile(const std::string& name);

        bool doesChatWork() const {return doesChatWork_;}
        void showMainMenu();
        void showChatMenu();
        std::shared_ptr<User> getCurrentUser() const {return currentUser_;}
        std::shared_ptr<User> getUserByLogin(const std::string& login);
        bool doesAliasExist(const std::string& alias);
        std::string hash_pass(const std::string& pass);
        
};