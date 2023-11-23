#include "Message.hpp"
#include <chrono>
#include <ctime>
void Message::write(std::fstream& os)
{
	auto time = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(time);
	os << std::ctime(&end_time);
	os << ' ';
	os << from_;
	os << ' ';
	os << to_;
	os << ' ';
	os << text_;
	os << std::endl;
}