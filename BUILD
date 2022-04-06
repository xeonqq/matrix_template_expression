
cc_binary(
    name = "invisible_proxy",
    srcs = glob([
        "*.cpp",
    ]),
    deps = [
	":lib"
    ],
)

cc_test(
    name = "lazy_str_concat_test",
    srcs = [
        "tests/lazy_str_concat_test.cpp",
        ],
    deps = [
	":lib",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_library(
	name = "lib",
	hdrs = glob(["includes/*h"]),
	includes = ["includes"],
)

