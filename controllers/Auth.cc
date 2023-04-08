#include "Auth.h"
#include "services/auth/Login.h" 
#include "services/auth/AuthException.h"

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
    } catch (const AuthException& ex) {
        json["error"] = ex.what();

        callback(HttpResponse::newHttpJsonResponse(json));
    }
}