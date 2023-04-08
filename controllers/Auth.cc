#include "Auth.h"
#include "services/Login.h" 

void Auth::login(const HttpRequestPtr& req,
    std::function<void(const HttpResponsePtr&)>&& callback,
    const std::string& username,
    const std::string& password)
{    
    Login loginService;
    
    Json::Value json;
    try {
        json["token"] = loginService.login(username, password);

        callback(HttpResponse::newHttpJsonResponse(json));
    } catch (const std::string& error_message) {
        json["error"] = error_message;

        callback(HttpResponse::newHttpJsonResponse(json));
    }
}