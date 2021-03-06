#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include <grpc/grpc.h>
#include <grpc++/security/server_credentials.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include "proto/cuba/hello/hello.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using hello::HelloRequest;
using hello::HelloReply;
using hello::HelloService;

int GL_INDEX = 0;

class HelloServiceImpl final : public HelloService::Service {
  Status Salute(ServerContext* context, const HelloRequest* request, HelloReply* reply) {
    GL_INDEX ++;
    std::stringstream prefix;
    prefix << "Hello Fidel! " << GL_INDEX;
    reply->set_message(prefix.str() + request->name() + "!");
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  HelloServiceImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}
