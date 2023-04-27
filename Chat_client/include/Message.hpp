#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Message{
    private:
        std::string from_; // All are constants for safety reasons
        std::string to_;
        std::string text_;
    public:
        Message() {};
        Message(const std::string& from, const std::string& to, const std::string& text) : from_(from), to_(to), text_(text) {}

        const std::string& getFrom() const {return from_;}
        const std::string& getTo() const {return to_;}
        const std::string& getText() const {return text_;}
        std::string tostr();
		std::fstream& operator >>(std::fstream& is);
	    std::ostream& operator <<(std::ostream& os);
};