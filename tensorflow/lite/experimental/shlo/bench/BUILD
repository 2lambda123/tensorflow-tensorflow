package(default_applicable_licenses = ["//tensorflow:license"])

cc_library(
    name = "util",
    srcs = [
    ],
    hdrs = [
        "util.h",
    ],
    deps = [
        "//tensorflow/lite/experimental/shlo:float",
    ],
)

cc_binary(
    name = "shlo_benchmark",
    srcs = [
        "shlo_benchmark.cc",
    ],
    deps = [
        ":util",
        "//tensorflow/lite/experimental/shlo",
        "//tensorflow/lite/experimental/shlo/test:util",
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/status",
        "@com_google_benchmark//:benchmark",
    ],
)

cc_binary(
    name = "xnn_benchmark",
    srcs = [
        "xnn_benchmark.cc",
    ],
    data = [
    ],
    deps = [
        ":util",
        "//tensorflow/lite/experimental/shlo:float",
        "@XNNPACK",
        "@com_google_absl//absl/log",
        "@com_google_benchmark//:benchmark",
    ],
)
