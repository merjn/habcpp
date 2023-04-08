#include "Login.h"
#include <string>
#include <drogon/drogon.h>
#include <drogon/orm/Result.h>
#include <sodium/crypto_pwhash.h>
#include "AuthException.cc"

std::string Login::login(const std::string& username, const std::string& password)
{
	if (username.length() == 0 || password.length() == 0)
	{
		throw AuthException("Username or password is too short");
	}

	auto clientPtr = drogon::app().getDbClient();
	auto result = clientPtr->execSqlAsyncFuture("select username,password from users where username = ?", username).get();

	if (result.affectedRows() != 1)
	{
		throw AuthException("Username or password is invalid");
	}

	for (auto& row : result)
	{
		const auto dbUser = row["username"].as<std::string>();
		const auto dbPassword = row["password"].as<std::string>();

		if (crypto_pwhash_str_verify(dbPassword.c_str(), password.c_str(), password.length()) != 0) {
			throw AuthException("Username or password is invalid");
		}
	}

	// Generate a JWT token for this user


	return std::string("jwt token here");
}