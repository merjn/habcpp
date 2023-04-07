#include "Login.h"
#include <string>
#include <drogon/drogon.h>
#include <drogon/orm/Result.h>

std::string Login::login(const std::string& username, const std::string& password)
{
	if (username.length() == 0 || password.length() == 0) {
		throw std::string("Username or password is too small");
	}

	auto clientPtr = drogon::app().getDbClient();
	auto result = clientPtr->execSqlAsyncFuture("select * from users where username = ?", username).get();

	for (auto& row : result)
	{
		std::cout << row["username"].as<std::string>() << std::endl;
		std::cout << row["password"].as<std::string>() << std::endl;
	}

	return std::string("jwt token here");
}