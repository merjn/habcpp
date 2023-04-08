#include "AuthException.h"

AuthException::AuthException(std::string&& msg) : message(std::move(msg)) { }

const char* AuthException::what() const noexcept
{
	return message.c_str();
}
