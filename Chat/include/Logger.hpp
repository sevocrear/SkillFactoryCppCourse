#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <shared_mutex>
#include <thread>
#ifndef __has_include
  static_assert(false, "__has_include not supported");
#else
#  if __cplusplus >= 201703L && __has_include(<filesystem>)
#    include <filesystem>
     namespace fs = std::filesystem;
#  elif __has_include(<experimental/filesystem>)
#    include <experimental/filesystem>
     namespace fs = std::experimental::filesystem;
#  elif __has_include(<boost/filesystem.hpp>)
#    include <boost/filesystem.hpp>
     namespace fs = boost::filesystem;
#  endif
#endif
#include "Message.hpp"

class Logger {
    private:
        std::string file_name_;
        std::fstream file_;
        void file_init(const std::string& file_name);
        std::shared_mutex shared_mutex_;

    public:
        Logger();
        std::string file_read_line();
        Logger(const std::string& file_name);
        void write_msg_info(const Message& msg);
        ~Logger();

};