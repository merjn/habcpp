#include <iostream>


class AuthException : public std::exception
{
private:
	std::string message;
public:
	AuthException(std::string&& msg) : message(msg) { }

	const char* what() const noexcept override {
		return message.c_str();
	}
};