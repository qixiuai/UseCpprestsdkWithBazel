
package(
    default_visibility = ["//visibility:public"],
)

licenses(["notice"])

cc_library(
    name = "cpprest",
    hdrs = glob(["cpprest/**/*.h", "cpprest/**/*.hpp", "pplx/**/*.h"]),
    includes = [".", "pplx"],
    deps = select({
        "@bazel_tools//src/conditions:windows" : [":cpprest_win"],
        "//conditions:default"   : [":cpprest_linux"],
    })
)

cc_import(
    name = "cpprest_linux",
    hdrs = glob(["cpprest/**/*.h", "cpprest/**/*.hpp"]),
    shared_library = "libcpprest.so",
)

cc_import(
    name = "cpprest_win",
    hdrs = glob(["cpprest/**/*.h", "cpprest/**/*.hpp"]),
    interface_library = "cpprest_2_10.lib",
    shared_library = "cpprest_2_10.dll",
)
