#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "Message.hpp"
class Common{
    private:
        std::string file_path_;
        
        int messages_len_ = 0;
        
    public:
        Common(std::string file_path): file_path_(file_path) {};
        void updateFile(Message obj_msg);
        std::vector<Message> readInfo();
        std::fstream openFile(const std::string& name);
        
};