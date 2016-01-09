load("/third_party/grpc/grpc_proto", "proto_library")

cc_binary(
  name = "cuba-server",
  srcs = [
    "cuba.cc",
  ],
  deps = [
    "//proto/cuba:hello",
  ],
)
