#include <iostream>


class AuthException : public std::exception
{
private:
	std::string message;
public:
	explicit AuthException(std::string&& msg);

	const char* what() const noexcept override;
};