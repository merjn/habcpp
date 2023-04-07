#include "IndexCtrl.h"

void IndexCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
	Json::Value json;
	json["message"] = std::string("Habcpp is ready");

	callback(HttpResponse::newHttpJsonResponse(json));
}
