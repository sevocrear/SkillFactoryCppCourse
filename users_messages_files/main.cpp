#include "include/User.hpp"
#include "include/Message.hpp"
using namespace std;
#include <filesystem>
namespace fs = std::filesystem;
int main() {

  // USERS INFO
  fstream user_file = fstream("users.txt", ios::in | ios::out);
	if (!user_file)  {
		// Для создания файла используем параметр ios::trunc
    user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);
    fs::permissions("users.txt",
        fs::perms::group_write | fs::perms::others_all,
        fs::perm_options::remove);
  }

	if (user_file) {
    // Чтение файла
		User obj;
    while (!user_file.eof()) {
      obj>>user_file;
      obj << std::cout << std::endl;
    }

    user_file.clear(std::ios_base::goodbit);

    // Запишем данные по в файл
    User obj1("alex90", "qwerty", "alexei97", "Alexei");
		obj1<< user_file;
	}
	else
	{
		cout << "Could not open file users.txt !" << '\n';
		return 0;

	}

  // MESSAGE INFO
  fstream msg_file = fstream("messages.txt", ios::in | ios::out);
	if (!msg_file) 
		// Для создания файла используем параметр ios::trunc
           msg_file = fstream("messages.txt", ios::in | ios::out | ios::trunc);
	
  fs::permissions("messages.txt",
        fs::perms::group_write | fs::perms::others_all,
        fs::perm_options::remove);

	if (msg_file) {
    // Чтение файла
		Message obj_msg;
    while (!msg_file.eof()) {
      obj_msg>>msg_file;
      obj_msg << std::cout << std::endl;
    }

    msg_file.clear(std::ios_base::goodbit);
    
    // Запишем данные по в файл
		Message obj_msg1("Alex_98", "sevocrear", "Hey");
		obj_msg1<<msg_file;
	}
	else
	{
		cout << "Could not open file users.txt !" << '\n';
		return 0;

	}

  return 0;
}