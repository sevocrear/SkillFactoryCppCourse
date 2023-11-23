#include "Logger.hpp"
// Constructor
void Logger::file_init(const std::string& file_name) {
    file_.open(file_name.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
    if (file_.is_open()) {
        std::cout << "Logging File is open" << std::endl;;
    }
}
// Constructor
Logger::Logger() {
    file_name_ = "log.txt";
    file_init(file_name_);
}

// Constructor
Logger::Logger(const std::string& file_name) {
    file_name_ =file_name;
    file_init(file_name_);
}

std::string Logger::file_read_line() {
    shared_mutex_.lock_shared();
    std::string line;
    std::getline(file_, line);
    shared_mutex_.unlock_shared();
    return line;
}

void Logger::write_msg_info(const Message& msg) {
    Message copy = msg;
    shared_mutex_.lock();
    copy.write(file_);
    shared_mutex_.unlock();
}

// Destructor
Logger::~Logger() {
    file_.close();
}