
package(
    default_visibility = ["//visibility:public"],
)

licenses(["notice"])


cc_binary(
    name = "server",
    srcs = ["main.cc", "server.cc", "server.h"],
    copts = ["-std=c++11", "-fpermissive", "-fexceptions"],
    linkopts = ["-lpthread"],
    deps = [
        "//third_party/libssl:libssl",
        "//third_party/libssl:crypto",
        "//third_party/boost:boost",
        "//third_party/cpprest:cpprest",
    ],
)

cc_binary(
    name = "client",
    srcs = ["client.cc"],
    copts = ["-std=c++14", "-fpermissive", "-fexceptions"],
    linkopts = ["-lpthread"], 
    deps = [
        "//third_party/cpprest:cpprest",
        "//third_party/libssl:libssl",
        "//third_party/libssl:crypto",
        "//third_party/boost:boost",
    ],
)

