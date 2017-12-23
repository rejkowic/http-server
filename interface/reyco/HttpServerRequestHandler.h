#include <optional>
#include <reyco/HttpServer.h>

namespace reyco {

class HttpServer::RequestHandler {
public:
  RequestHandler(std::string_view id, HttpServer &server);
  virtual ~RequestHandler();

  virtual std::string response() = 0;

private:
  const std::string_view id;
  HttpServer &server;
};
}
