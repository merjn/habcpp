#include <string>

class ValidationException : public std::exception
{
public:
	ValidationException(std::string&& msg) : message(std::move(msg)) { }

	const char* what() const noexcept override;
private:
	std::string message;
};