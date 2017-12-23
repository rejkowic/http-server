#pragma once
#include <memory>

namespace reyco {

class HttpServer {
public:
  class RequestHandler;
  class Config;
  class Instance;

  static std::unique_ptr<HttpServer> make();
  virtual ~HttpServer();

protected:
  virtual std::string handleRequest() = 0;
  virtual HttpServer &registerHandler(std::string_view id,
                                      RequestHandler &handler) = 0;
  virtual void unregisterHandler(std::string_view id) = 0;
};
}
