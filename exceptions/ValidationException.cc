#include "ValidationException.h"

const char* ValidationException::what() const noexcept override
{
	return message.c_str();
}