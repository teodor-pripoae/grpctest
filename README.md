# grpctest

## Build

```
$ bazel build //cuba:cuba-server # build the server
$ bazel build //cordoba:cordoba-client # build the client

$ ./bazel-bin/cuba/cuba-server # start the server
$ ./bazel-bin/cordoba/cordoba-client # Run the client
Greeter received: Buenos dias presidente Fidel!
Elapsed time: 0.00087654700000000
Greeter received: Buenos dias presidente Fidel!
Elapsed time: 0.00000025000000000
```
