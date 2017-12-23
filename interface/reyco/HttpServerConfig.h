#pragma once
#include <reyco/HttpServer.h>

namespace reyco {

class HttpServer::Config {
public:
  const std::string& port;
};
}
