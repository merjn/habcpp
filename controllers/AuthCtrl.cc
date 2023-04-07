#include "AuthCtrl.h"
#include "usecases/Login.h" 

void AuthCtrl::login(const HttpRequestPtr& req,
    std::function<void(const HttpResponsePtr&)>&& callback,
    const std::string& username,
    const std::string& password)
{    
    Login login_service;
    
    Json::Value json;
    try {
        json["token"] = login_service.login(username, password);

        callback(HttpResponse::newHttpJsonResponse(json));
    } catch (const std::string& error_message) {
        json["error"] = error_message;

        callback(HttpResponse::newHttpJsonResponse(json));
    }
}