#include <iostream>
#include <reyco/AppFactory.h>
#include <reyco/HttpServerConfig.h>
#include <reyco/HttpServerInstance.h>
#include <reyco/HttpServerRequestHandler.h>

namespace reyco {

class MyHandler : public HttpServer::RequestHandler {
public:
  using RequestHandler::RequestHandler;

  std::string response() override { return "OK"; }
};

class MyInstance : public HttpServer::Instance {
public:
  using Instance::Instance;

  virtual void start() override { std::cout << handleRequest() << std::endl; }
};

void main() {
  HttpServer::Config conf{"8080"};
  auto server = HttpServer::make();
  MyInstance instance(*server, conf);
  MyHandler handler("main", *server);
  instance.start();
}
}

int main() { return reyco::AppFactory::make(reyco::main); }
