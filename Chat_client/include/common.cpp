#include "common.hpp"

namespace fs = std::filesystem;


std::fstream Common::openFile(const std::string &name)
{
    // USERS INFO
    std::fstream user_file = std::fstream(name, std::ios::in | std::ios::out);
    if (!user_file)
    {
        // Для создания файла используем параметр ios::trunc
        user_file = std::fstream(name, std::ios::in | std::ios::out | std::ios::trunc);
        fs::permissions(name,
                        fs::perms::group_write | fs::perms::others_all,
                        fs::perm_options::remove);
    }
    return user_file;
}

std::vector<Message> Common::readInfo()
{
    std::fstream file = this->openFile(file_path_);
    int messages_file_len = std::count(std::istreambuf_iterator<char>(file), 
             std::istreambuf_iterator<char>(), '\n');
    file.seekp(0, std::ios::beg); // move to start
    std::vector<Message> msgs;
    if (file && (messages_len_ < messages_file_len))
    {
        // Чтение файла и обновление списка пользователей
        int idx = 0;
        while (!file.eof() && (idx < messages_file_len))
        {
            Message obj;
            obj>>file;
            if (idx >= messages_len_) {
                msgs.push_back(obj);
            }
            idx ++;
        }
        messages_len_ = messages_file_len;
    }
    else if (!file)
    {
        std::cout << "Could not open file "<< file_path_ << "!" << '\n';
        return msgs;
    }
    return msgs;
}

void Common::updateFile(Message obj_msg) {
    // Update File
    std::fstream file = this->openFile(file_path_);
    file.seekp(0, std::ios::end); // move to end
    obj_msg<<file;
}