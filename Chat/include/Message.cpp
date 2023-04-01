#include "Message.hpp"

std::fstream& Message::operator >>(std::fstream& is)
{
	is >> from_;
	is >> to_;
	is.ignore();
    std::getline(is, text_);
	return is;
}
std::ostream& Message::operator <<(std::ostream& os)
{
	os << std::endl;
	os << from_;
	os << ' ';
	os << to_;
	os << ' ';
	os << text_;
	return os;
}