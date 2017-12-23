#include "HttpServerImpl.h"

namespace reyco {

std::unique_ptr<HttpServer> HttpServer::make() {
  return std::make_unique<HttpServerImpl>();
}

HttpServer::~HttpServer() = default;

HttpServer::RequestHandler::RequestHandler(std::string_view id,
                                           HttpServer &server)
    : id(id), server(server.registerHandler(id, *this)) {}

HttpServer::RequestHandler::~RequestHandler() { server.unregisterHandler(id); }

HttpServer::Instance::Instance(HttpServer &server,
                               const HttpServer::Config &conf)
    : server(server), conf(conf) {}

std::string HttpServer::Instance::handleRequest() {
  return server.handleRequest();
}

HttpServer::Instance::~Instance() = default;
}
