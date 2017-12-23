#pragma once
#include <reyco/HttpServer.h>

namespace reyco {


class HttpServer::Instance{
public:
  Instance(HttpServer& server, const HttpServer::Config& conf);
  virtual ~Instance();

  virtual void start() = 0;

protected:
  std::string handleRequest();

  HttpServer& server;
  const HttpServer::Config& conf;
};

}
