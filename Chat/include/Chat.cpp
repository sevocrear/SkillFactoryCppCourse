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

void Chat::readUsersInfo()
{
    // query data
    const auto users = conn_->execute("SELECT users.id, users.login, users.alias, users.name, users.surname, password_hashes.hash FROM users LEFT JOIN password_hashes ON users.id = password_hashes.user_id WHERE password_hashes.hash IS NOT NULL");

    // iterate and convert results
    for (const auto &row : users)
    {
        User obj(row["login"].as<std::string>(), row["hash"].as<std::string>(), row["alias"].as<std::string>(), row["name"].as<std::string>() + row["surname"].as<std::string>());
        users_.push_back(obj);
        hash_table_.insert({obj.getUserLogin(), obj.getUserPassword()});
    }
}

void Chat::start()
{
    doesChatWork_ = true;

    // prepare statements
    conn_->prepare("insert_user", "INSERT INTO users ( login, alias, name, surname ) VALUES ( $1, $2, $3, $4 )");
    conn_->prepare("insert_hash_pass", "UPDATE password_hashes SET hash = $2 WHERE user_id = (SELECT id FROM users WHERE login = $1);");
    conn_->prepare("insert_message", "INSERT INTO messages ( \"to\", \"from\", text, date) VALUES ( $1, $2, $3, $4 )");
}

std::shared_ptr<User> Chat::getUserByLogin(const std::string &login)
{
    /// @brief Finds user with given login if exists
    /// @param login
    /// @return std::shared_ptr<User> user
    std::shared_ptr<User> current_user = nullptr;

    const auto users = conn_->execute("SELECT users.id, users.login, users.alias, users.name, users.surname, password_hashes.hash FROM users LEFT JOIN password_hashes ON users.id = password_hashes.user_id WHERE password_hashes.hash IS NOT NULL AND login =  $1", login);
    if (!users.empty())
    {
        for (const auto &row : users)
        {
            User obj(row["login"].as<std::string>(), row["alias"].as<std::string>(), row["hash"].as<std::string>(), row["name"].as<std::string>() + row["surname"].as<std::string>());
            current_user = std::make_shared<User>(obj);
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

        // Verify password
        const auto password_ok = conn_->execute("SELECT EXISTS ( SELECT 1 FROM users INNER JOIN password_hashes ON users.id = password_hashes.user_id WHERE users.login = $1 AND password_hashes.hash = $2 );", login, hash_pass(password));

        if (currentUser_ == nullptr || (!password_ok.at(0).as<bool>()))
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
    const auto users = conn_->execute("SELECT users.id, users.login, users.alias, users.name, users.surname, password_hashes.hash FROM users LEFT JOIN password_hashes ON users.id = password_hashes.user_id WHERE password_hashes.hash IS NOT NULL AND alias =  $1", alias);

    return !users.empty();
}

void Chat::cin_data(std::string& login, std::string& password, std::string& alias, std::string& name, std::string& surname) {
    std::cout << "\x1B[34mlogin (should be unique, private):\033[0m\t\t" << std::endl;
    std::cin >> login;

    std::cout << "\x1B[34mpassword:\033[0m\t\t" << std::endl;
    std::cin >> password;

    std::cout << "\x1B[34malias (should be unique, public):\033[0m\t\t" << std::endl;
    std::cin >> alias;

    std::cout << "\x1B[34mname:\033[0m\t\t" << std::endl;

    std::cin >> name;

    std::cout << "\x1B[34msurname:\033[0m\t\t" << std::endl;
    std::cin >> surname;
}

void Chat::sign_up()
{
    /// @brief Signs up with given login, pass and name. Same logins aren't possible
    std::string login, password, alias, name, surname;

    cin_data(login, password, alias, name, surname);

    if (getUserByLogin(login))
    {
        // throw UserLoginExp();
        std::cout << "\x1B[31m login " << login <<" is busy, choose another one\033[0m\t\t" << std::endl;
        cin_data(login, password, alias, name, surname);
    }

    if (doesAliasExist(alias) || alias == "all")
    {
        // throw UserLoginExp();
        std::cout << "\x1B[31m alias " << alias <<" is busy,  it should be unique. Choose another one\033[0m\t\t" << std::endl;
        cin_data(login, password, alias, name, surname);
    }
    std::cout << login << std::endl;
    std::cout << alias << std::endl;
    std::cout << surname << std::endl;
    std::cout << name << std::endl;
    // Switch to User
    User user = User(login, alias, name, surname);
    currentUser_ = std::make_shared<User>(user);

    // Add USER to DATABASE
    // begin transaction
    const auto tr = conn_->transaction();

    // execute previously prepared statements
    tr->execute("insert_user", login, alias, name, surname);
    tr->execute("insert_hash_pass", login, hash_pass(password));
    // commit transaction
    tr->commit();

    users_.push_back(user);
    hash_table_.insert({login, hash_pass(password)});

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

        {
            // begin transaction
            const auto tr = conn_->transaction();

            auto t = std::time(nullptr);
            auto tm = *std::localtime(&t);
            std::ostringstream oss;
            oss << std::put_time(&tm, "%Y-%m-%d");
            std::string str_date = oss.str();

            // execute previously prepared statements
            tr->execute("insert_message", to, currentUser_->getUserAlias(), text, str_date.c_str());

            // commit transaction
            tr->commit();
        }

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
    std::cout << "\x1B[90m\nStart of the Chat\n\033[0m\t\t" << std::endl;

    const auto messages = conn_->execute("SELECT * FROM messages WHERE (\"to\" =$1 OR \"from\" = $1 OR \"to\"='all') AND date >= NOW() - INTERVAL '1 day' ORDER BY date DESC;", currentUser_->getUserAlias());

    for (const auto &row : messages)
    {
        if (row[ "from" ].as< std::string >() == currentUser_->getUserAlias())
        {
            std::cout << "\x1B[36mFrom:" << row[ "from" ].as< std::string >() << " (me)\033[0m\t\t" << std::endl;
        }
        else
        {
            std::cout << "\x1B[36mFrom:" << row[ "from" ].as< std::string >() << "\033[0m\t\t" << std::endl;
        }
        std::cout << "\x1B[97m" << row[ "text" ].as< std::string >() << "\033[0m\t\t" << std::endl;
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
