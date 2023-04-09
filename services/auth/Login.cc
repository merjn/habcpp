#include "Login.h"
#include <string>
#include <drogon/drogon.h>
#include <drogon/orm/Result.h>
#include <sodium/crypto_pwhash.h>
#include "AuthException.h"
#include "jwt/jwt.hpp"

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

	// The process of allocating a new JWT object to the stack and retrieving the key can easily
	// be done in a separate singleton instance. However, let's just make the following work and refactor
	// it when there's a minimum viable product.
	const auto key = drogon::app().getCustomConfig().get("jwt_secret", "").as<std::string>();
	if (key == "")
	{
		throw AuthException("JWT secret is undefined");
	}

	using namespace jwt::params;

	jwt::jwt_object obj{ algorithm("HS256"), payload({ {"username", username}}), secret(key) };

	return obj.signature();
}