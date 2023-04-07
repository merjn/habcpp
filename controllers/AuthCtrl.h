#pragma once

#include <drogon/HttpSimpleController.h>
#include <drogon/HttpController.h>

using namespace drogon;

class AuthCtrl : public drogon::HttpController<AuthCtrl>
{
  public:
      METHOD_LIST_BEGIN
      METHOD_ADD(AuthCtrl::login, "/login?username={1}&password={2}", Post);
      METHOD_LIST_END

      void login(const HttpRequestPtr& req,
          std::function<void(const HttpResponsePtr&)>&& callback,
          const std::string &username,
          const std::string &password);
};
