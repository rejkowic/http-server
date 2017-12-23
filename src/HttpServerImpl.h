#include <functional>
#include <reyco/HttpServerConfig.h>
#include <reyco/HttpServerInstance.h>
#include <reyco/HttpServerRequestHandler.h>
#include <unordered_map>

namespace reyco {

class HttpServerImpl : public HttpServer {
private:
  std::string handleRequest() override {
    for (auto &h : reqHandlers) {
      RequestHandler &reqHandler = h.second.get();
      return reqHandler.response();
    }
    return "";
  }

  HttpServer &registerHandler(std::string_view id,
                              RequestHandler &handler) override {
    reqHandlers.emplace(id, handler);
    return *this;
  }
  void unregisterHandler(std::string_view id) override {
    reqHandlers.erase(id);
  }

  using RequestHandlerRef = std::reference_wrapper<RequestHandler>;
  std::unordered_map<std::string_view, RequestHandlerRef> reqHandlers;
};
}
