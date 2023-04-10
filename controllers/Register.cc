#include "Register.h";
#include "../viewmodels/RegisterViewModel.h";

void Register::createAccount(const HttpRequestPtr& request, std::function<void(const HttpResponsePtr&)> &&callback, habcpp::RegisterViewModel &&vm)
{
	std::cout << vm.username << std::endl;

	callback(HttpResponse::newHttpResponse());
}
