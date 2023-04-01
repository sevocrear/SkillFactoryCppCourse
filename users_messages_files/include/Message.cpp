#include "Message.hpp"

std::fstream& Message::operator >>(std::fstream& is)
{
	std::string from = from_;
	std::string to = to_;
	std::string text = text_;
	is >> from;
	is >> to;
	is >> text;
	return is;
}
std::ostream& Message::operator <<(std::ostream& os)
{
	os << from_;
	os << ' ';
	os << to_;
	os << ' ';
	os << text_;
	os << std::endl;
	return os;
}