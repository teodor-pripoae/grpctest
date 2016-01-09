#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include "proto/cuba/hello/hello.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using hello::HelloRequest;
using hello::HelloReply;
using hello::HelloService;

class HelloClient {
 public:
  HelloClient(std::shared_ptr<Channel> channel)
      : stub_(HelloService::NewStub(channel)) {}

  std::string Salute(const std::string& user) {
    HelloRequest request;
    request.set_name(user);
    HelloReply reply;
    ClientContext context;

    Status status = stub_->Salute(&context, request, &reply);
    if (status.ok()) {
      return reply.message();
    } else {
      return "Rpc failed";
    }
  }

 private:
  std::unique_ptr<HelloService::Stub> stub_;
};

int main(int argc, char** argv) {
  HelloClient client(
      grpc::CreateChannel("localhost:50051", grpc::InsecureCredentials()));
  std::string user("Fidel");
  std::string reply = client.Salute(user);
  std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}
