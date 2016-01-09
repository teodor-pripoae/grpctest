load("/third_party/grpc/grpc_proto", "proto_library")

proto_library(
  name = "hello",
  src = "hello/hello.proto",
  has_service = True,
  generate_cc = True,
  generate_java = False,
  visibility = [
    "//cuba:__pkg__",
    "//cordoba:__pkg__",
  ]
)
