#include "RegisterViewModel.h"
#include <drogon/HttpRequest.h>
#include "../exceptions/ValidationException.h";

namespace drogon
{
	template<> 
	inline habcpp::RegisterViewModel fromRequest(const HttpRequest& req)
	{
		const std::shared_ptr json = req.getJsonObject();
		if (json == nullptr)
		{
			throw ValidationException("Cannot read JSON data for RegisterViewModel");
		}

		habcpp::RegisterViewModel viewModel;

		viewModel.username = (*json)["username"].asString();

		return viewModel;
	}
}