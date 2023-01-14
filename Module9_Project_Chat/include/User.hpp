#pragma once
#include <string>

class User {
    private:
        const std::string login_; // User can't change login
        std::string password_;
        std::string name_;
    public:
        User(const std::string& login, const std::string password, const std::string& name): login_(login), password_(password), name_(name) {}

        void setUserName(const std::string& name) {name_ = name;}
        const std::string& getUserName() const {return name_;}

        void setUserPassword(const std::string& password) {password_ = password;}
        const std::string& getUserPassword() const {return password_;}

        const std::string& getUserLogin() const {return login_;}
};