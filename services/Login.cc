#include "Login.h"
#include <string>
#include <drogon/drogon.h>
#include <drogon/orm/Result.h>
#include <sodium/crypto_pwhash.h>

std::string Login::login(const std::string& username, const std::string& password)
{
	if (username.length() == 0 || password.length() == 0) {
		throw std::string("Username or password is too small");
	}

	auto clientPtr = drogon::app().getDbClient();
	auto result = clientPtr->execSqlAsyncFuture("select * from users where username = ?", username).get();

	for (auto& row : result)
	{
		const auto dbUser = row["username"].as<std::string>();
		const auto dbPassword = row["password"].as<char*>();

		if (crypto_pwhash_str_verify(dbPassword, password.c_str(), password.length()) != 0) {
			throw std::string("Username or password is invalid");
		}
	}

	// Generate a JWT token for this user


	return std::string("jwt token here");
}