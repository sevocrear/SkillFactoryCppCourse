#include "User.hpp"

std::fstream& User::operator >>(std::fstream& is)
{
	is >> login_;
	is >> password_;
	is >> alias_;
    is.ignore();
    std::getline(is, name_);
	return is;
}
std::ostream& User::operator <<(std::ostream& os)
{
	os << std::endl;
	os << login_;
	os << ' ';
	os << password_;
	os << ' ';
	os << alias_;
    os << ' ';
	os << name_;
	return os;
}