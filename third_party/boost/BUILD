
package(
    default_visibility = ["//visibility:public"],
)

licenses(["notice"])

cc_library(
    name = "boost",
    copts = ["-std=c++17"],
    hdrs = glob(["boost/**/*.hpp"]),
    includes = ["."],
    deps = select({
        "@bazel_tools//src/conditions:windows" : [":boost_win"],
        "//conditions:default" : [":boost_linux"],
    })
)

cc_import(
    name = "boost_linux",
    hdrs = glob(["boost/**/*.hpp"]),
    shared_library = "boost/libboost_system.so",
)

cc_import(
    name = "boost_win",
    hdrs = glob(["boost/**/*.hpp"]),
    interface_library = "boost/boost_system-vc140-mt.lib",
    shared_library = "boost/boost_system-vc141-mt-x32-1_69.dll",
)
