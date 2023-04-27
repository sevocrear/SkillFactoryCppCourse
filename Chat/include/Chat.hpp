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

        std::string users_file_path_, messages_file_path_send_, messages_file_path_receive_;
        bool doesChatWork_ = false;

        std::vector<User> users_;
        int users_len_ = 0;
        std::vector<Message> messages_;
        int messages_len_receive_, messages_len_send_ = 0;
        std::unordered_map<std::string, std::string> hash_table_;

        void log_in();
        void sign_up();
        // void showChat() const;
        // void showAllUsersNames() const;
        void write_message();
        void read_messages();

        int hash_func(const std::string& login, int offset);
    public:
        void start(std::string users_file_path, std::string messages_file_path_send, std::string messages_file_path_receive);
        void readUsersInfo();
        void readMessagesInfo(std::string file_path, std::string flag = "receive");
        std::fstream openFile(const std::string& name);

        bool doesChatWork() const {return doesChatWork_;}
        void showMainMenu();
        void showChatMenu();
        std::shared_ptr<User> getCurrentUser() const {return currentUser_;}
        std::shared_ptr<User> getUserByLogin(const std::string& login);
        bool doesAliasExist(const std::string& alias);
        std::string hash_pass(const std::string& pass);
        
};