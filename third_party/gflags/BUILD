licenses(["notice"])

cc_library(
  visibility = ["//visibility:public"],
  includes = [
    "compile/k8/include",
  ],
  srcs = [
    "upstream/src/gflags.cc",
    "upstream/src/gflags_completions.cc",
    "upstream/src/gflags_reporting.cc",
  ],
  hdrs = [
    "compile/k8/include/gflags/gflags.h",
    "compile/k8/include/gflags/gflags_completions.h",
    "compile/k8/include/gflags/gflags_declare.h",
    "compile/k8/include/gflags/gflags_gflags.h",
  ],
  name = "gflags",
  copts = [
    "-Ithird_party/gflags/compile/k8/include/gflags",
  ],
  linkopts = [
    "-pthread",
  ],
)

cc_test(
  srcs = [
    "upstream/test/gflags_unittest.cc",
  ],
  copts = [
    "-Ithird_party/gflags/compile/k8/include/gflags",  # We need "config.h"
    "-Ithird_party/gflags/upstream/src",
  ],
  name = "gflags_unittest",
  deps = [
    ":gflags"
  ],
)

