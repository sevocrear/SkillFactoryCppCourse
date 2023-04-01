#include <fstream>
#include <iostream>
using namespace std;

class User {
	string _name;
	string _login;
	string _pass;

public:
	User(string name, string login, string pass):_name(name), _login(login), _pass(pass) {}
	
	friend fstream& operator >>(fstream& is, User& obj);
	friend ostream& operator <<(ostream& os, const User& obj);
};

fstream& operator >>(fstream& is, User& obj)
{
	is >> obj._name;
	is >> obj._login;
	is >> obj._pass;
	return is;
}
ostream& operator <<(ostream& os, const User& obj)
{
	os << obj._name;
	os << ' ';
	os << obj._login;
	os << ' ';
	os << obj._pass;
	return os;
}
int main() {

	fstream user_file = fstream("users.txt", ios::in | ios::out);
	if (!user_file) 
		// Для создания файла используем параметр ios::trunc
           user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);
	
	if (user_file) {
		User obj("Alex", "qwerty", "12345");
           // Запишем данные по в файл
		user_file << obj << endl;
           // Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		user_file.seekg(0, ios_base::beg);
           // Считываем данные из файла
		user_file >> obj;
		cout << obj << endl;
	}
	else
	{
		cout << "Could not open file users.txt !" << '\n';
		return 0;

	}
}