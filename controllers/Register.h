#pragma once

#include <drogon/HttpSimpleController.h>
#include <drogon/HttpController.h>
#include "../viewmodels/RegisterViewModel.h";

using namespace drogon;

class Register : public drogon::HttpController<Register>
{
public:
	METHOD_LIST_BEGIN
		METHOD_ADD(Register::createAccount, "/createAccount", Post);
	METHOD_LIST_END

	void createAccount(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr&)>&& callback, habcpp::RegisterViewModel &&vm);
};