#include "User.hpp"

std::fstream& User::operator >>(std::fstream& is)
{
	is >> login_;
	is >> password_;
	is >> alias_;
    is >> name_;
	return is;
}
std::ostream& User::operator <<(std::ostream& os)
{
	os << login_;
	os << ' ';
	os << password_;
	os << ' ';
	os << alias_;
    os << ' ';
	os << name_;
	os << std::endl;
	return os;
}