#include "Chat.hpp"
namespace fs = std::filesystem;
int Chat::hash_func(const std::string &login, int offset)
{
    // вычисляем индекс
    int sum = 0, i = 0;
    for (; i < login.length(); i++)
    {
        sum = sum * 25 + login[i]; // метод умноженя
    }
    // второе хеширование
    int f2 = sum % (hash_table_.size() * 2);
    // проба
    return (sum % hash_table_.size() + offset * offset) % hash_table_.size(); // квадратичны метод составления хэш-таблицы
}

std::string Chat::hash_pass(const std::string &pass)
{
    unsigned int hash = 5381;
    for (int i = 0; i < pass.length(); i++)
    {
        hash = ((hash << 5) + hash) + pass[i];
    }
    return std::to_string(hash);
}

std::fstream Chat::openFile(const std::string &name)
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

void Chat::readUsersInfo()
{
    std::fstream user_file = this->openFile(users_file_path_);
    int users_file_len = std::count(std::istreambuf_iterator<char>(user_file), 
             std::istreambuf_iterator<char>(), '\n');
    user_file.seekp(0, std::ios::beg); // move to start
    if (user_file && (users_len_ < users_file_len))
    {
        // Чтение файла и обновление списка пользователей
        User obj;
        int idx = 0;
        while (!user_file.eof() && idx < users_file_len)
        {
            obj>>user_file;
            if (idx >= users_len_) {
                users_.push_back(obj);
                hash_table_.insert({obj.getUserLogin(), obj.getUserPassword()});
            }
            idx ++;
        }
        users_len_ = users_file_len;
    }
    else if (!user_file)
    {
        std::cout << "Could not open file "<< users_file_path_ << "!" << '\n';
        return;
    }
}

void Chat::readMessagesInfo()
{
    std::fstream file = this->openFile(messages_file_path_);
    int messages_file_len = std::count(std::istreambuf_iterator<char>(file), 
             std::istreambuf_iterator<char>(), '\n');
    file.seekp(0, std::ios::beg); // move to start
    if (file && (messages_len_ < messages_file_len))
    {
        // Чтение файла и обновление списка пользователей
        int idx = 1;
        while (!file.eof())
        {
            Message obj;
            obj>>file;
            if ((idx > messages_len_) || (messages_len_ == 0 && idx == 0)) {
                std::cout << idx << std::endl;
                messages_.push_back(obj);
            }
            idx ++;
        }
        messages_len_ = messages_file_len;
    }
    else if (!file)
    {
        std::cout << "Could not open file "<< messages_file_path_ << "!" << '\n';
        return;
    }
}

void Chat::start(std::string users_file_path, std::string messages_file_path)
{
    doesChatWork_ = true;
    users_file_path_ = users_file_path;
    messages_file_path_ = messages_file_path;
    this->readUsersInfo();
    this->readMessagesInfo();
    // Read info from files about users and messages
}

std::shared_ptr<User> Chat::getUserByLogin(const std::string &login)
{
    /// @brief Finds user with given login if exists
    /// @param login
    /// @return std::shared_ptr<User> user
    std::shared_ptr<User> current_user = nullptr;
    for (auto &user : users_)
    {
        if (login == user.getUserLogin())
        {
            current_user = std::make_shared<User>(user);
        }
    }
    return current_user;
}

void Chat::log_in()
{
    /// @brief Logins into the chat by given log-pass
    std::string login, password;
    char operation;
    while (!currentUser_)
    {
        std::cout << "\x1B[34mlogin:\033[0m\t\t" << std::endl;
        std::cin >> login;

        std::cout << "\x1B[34mpassword:\033[0m\t\t" << std::endl;
        std::cin >> password;

        currentUser_ = getUserByLogin(login);

        std::unordered_map<std::string, std::string>::iterator it = hash_table_.find(login);

        if (currentUser_ == nullptr || (it == hash_table_.end()) || (hash_pass(password) != it->second))
        {
            currentUser_ = nullptr; // if password is wrong, reset current user

            std::cout << "\x1B[31mlogin failed... Check login and password...\033[0m\t\t" << std::endl;

            std::cout << "\x1B[34m(0) Repeat login\033[0m\t\t" << std::endl;
            std::cout << "\x1B[34m(1) Exit\033[0m\t\t" << std::endl;

            std::cin >> operation;
            if (operation == '1')
            {
                break;
            }
        }
    }
    std::cout << "\x1B[32mLogin Successful!\033[0m\t\t" << std::endl;
}

bool Chat::doesAliasExist(const std::string &alias)
{
    /// @brief Checks if user with @alias exists.
    /// @param alias - user's alias
    /// @return boolean. True is exists
    for (auto &user : users_)
    {
        if (alias == user.getUserAlias())
        {
            return true;
        }
    }
    return false;
}
void Chat::sign_up()
{
    /// @brief Signs up with given login, pass and name. Same logins aren't possible
    std::string login, password, alias, name;

    std::cout << "\x1B[34mlogin (should be unique, private):\033[0m\t\t" << std::endl;
    std::cin >> login;

    std::cout << "\x1B[34mpassword:\033[0m\t\t" << std::endl;
    std::cin >> password;

    std::cout << "\x1B[34malias (should be unique, public):\033[0m\t\t" << std::endl;
    std::cin >> alias;

    std::cout << "\x1B[34mname:\033[0m\t\t" << std::endl;

    std::cin.ignore();
    std::getline(std::cin, name);

    if (getUserByLogin(login))
    {
        // throw UserLoginExp();
        std::cout << "\x1B[31m login is busy, choose another one\033[0m\t\t" << std::endl;
        sign_up();
    }

    if (doesAliasExist(alias) || alias == "all")
    {
        // throw UserLoginExp();
        std::cout << "\x1B[31m alias is busy,  it should be unique. Choose another one\033[0m\t\t" << std::endl;
        sign_up();
    }

    User user = User(login, alias, name);
    users_.push_back(user);
    hash_table_.insert({login, hash_pass(password)});

    // Update File
    User usr_obj = User(login, hash_pass(password), alias, name);
    std::fstream file = this->openFile(users_file_path_);
    file.seekp(0, std::ios::end); // move to end
    usr_obj<<file;

    // std::unordered_map <std::string, std::string>::iterator it = hash_table_.find(login);
    // std::cout << it->first << std::endl;
    currentUser_ = std::make_shared<User>(user);
    std::cout << "\x1B[32mRegistration Successful!\033[0m\t\t" << std::endl;
}

void Chat::showMainMenu()
{
    /// @brief Show Main Menu of the chat
    char operation;
    currentUser_ = nullptr;

    while (doesChatWork() && !currentUser_)
    { // While chat works and user is not selected
        std::cout << "\x1B[37mMain Menu\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(0) Register\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(1) Login\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(2) Quit\033[0m\t\t" << std::endl;

        std::cin >> operation;
        switch (operation)
        {
        case '0': // Register
            sign_up();
            break;
        case '1': // Login
            log_in();
            break;
        case '2':
            doesChatWork_ = false;
            break;
        default:
            std::cout << "\x1B[31mTry again...\033[0m\t\t" << std::endl;
            break;
        }
    }
}

void Chat::write_message()
{
    /// @brief Write message and send it to someone by @alias
    std::string to, text;

    std::cout << "\x1B[36mTo (alias or all):\033[0m\t\t" << std::endl;
    std::cin >> to;

    std::cout << "\x1B[36mText:\033[0m\t\t" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, text);

    if (doesAliasExist(to) || to == "all")
    {
        Message obj_msg = Message(currentUser_->getUserAlias(), to, text);
        // Update File
        std::fstream file = this->openFile(messages_file_path_);
        file.seekp(0, std::ios::end); // move to end
        obj_msg<<file;

        std::cout << "\x1B[32mMessage sent!\033[0m\t\t" << std::endl;
    }
    else
    {
        std::cout << "\x1B[31merror sensing message. Can't find user by given alias\033[0m\t\t" << std::endl;
        return;
    }
}

void Chat::read_messages()
{
    // Get Info From txt files
    this->readUsersInfo();
    this->readMessagesInfo();
    std::cout << "\x1B[90m\nStart of the Chat\n\033[0m\t\t" << std::endl;

    for (auto &message : messages_)
    {
        if (message.getTo() == currentUser_->getUserAlias() || message.getTo() == "all")
        {
            if (message.getFrom() == currentUser_->getUserAlias())
            {
                std::cout << "\x1B[36mFrom:" << message.getFrom() << " (me)\033[0m\t\t" << std::endl;
            }
            else
            {
                std::cout << "\x1B[36mFrom:" << message.getFrom() << "\033[0m\t\t" << std::endl;
            }
            std::cout << "\x1B[97m" << message.getText() << "\033[0m\t\t" << std::endl;
        }
    }
    std::cout << "\x1B[90m\nEnd of the Chat\n\033[0m\t\t" << std::endl;
}
void Chat::showChatMenu()
{
    /// @brief Shows Chan Menu to send, read messages and log out
    char operation;

    while (doesChatWork() && currentUser_)
    { // While chat works and user didn't log out
        std::cout << "\x1B[37mChat Menu\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(0) Send Message\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(1) Read Messages\033[0m\t\t" << std::endl;
        std::cout << "\x1B[37m(2) Log out\033[0m\t\t" << std::endl;

        std::cin >> operation;
        switch (operation)
        {
        case '0': // Send Message
            write_message();
            break;
        case '1': // Read Messages
            read_messages();
            break;
        case '2': // Log out
            currentUser_ = nullptr;
            break;
        default:
            std::cout << "\x1B[31mTry again...\033[0m\t\t" << std::endl;
            break;
        }
    }
}
