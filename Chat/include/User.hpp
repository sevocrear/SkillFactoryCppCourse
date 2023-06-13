#pragma once
#include <string>
#include <fstream>
#include <iostream>

class User {
    private:
        std::string login_; // User can't change login
        std::string password_;
        std::string alias_; // alias as in telegram, for ex., to identificate users in chat
        std::string name_; 
        std::string surname_;
    public:
        User() {};

        User(const std::string& login, const std::string& alias, const std::string& name, const std::string& surname): login_(login), alias_(alias), name_(name), surname_(surname) {}

        User(const std::string& login, const std::string& alias, const std::string& pass, const std::string& name, const std::string& surname): login_(login), password_(pass), alias_(alias), name_(name), surname_(surname){}

        void setUserName(const std::string& name) {name_ = name;}
        const std::string& getUserName() const {return name_;}
        
        void setUserSurname(const std::string& surname) {surname_ = surname;}
        const std::string& getUserSurname() const {return surname_;}

        void setUserPassword(const std::string& password) {password_ = password;}
        const std::string& getUserPassword() const {return password_;}

        const std::string& getUserLogin() const {return login_;}

        void setUserAlias(const std::string& alias) {alias_ = alias;}
        const std::string& getUserAlias() const {return alias_;}

        std::fstream& operator >>(std::fstream& is);
	    std::ostream& operator <<(std::ostream& os);
};