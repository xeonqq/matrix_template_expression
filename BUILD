
cc_binary(
    name = "invisible_proxy",
    srcs = glob([
        "*.cpp",
    ]),
    deps = [
	":lib"
    ],
)

cc_library(
	name = "lib",
	hdrs = glob(["includes/*h"]),
	#srcs = glob(["lib/*.cpp"]),
	includes = ["includes"],
)

