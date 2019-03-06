
package(
    default_visibility = ["//visibility:public"],
)

licenses(["notice"])


cc_library(
    name = "crypto",
    deps = select({
        "@bazel_tools//src/conditions:windows" : [":ssl_win"],
        "//conditions:default" : [":crypto_linux"],
    }),
)

cc_import(
    name = "crypto_linux",
    shared_library = "libcrypto.so",
)


cc_library(
    name = "libssl",
    deps = select({
        "@bazel_tools//src/conditions:windows" : [":ssl_win"],
        "//conditions:default" : [":libssl_linux"],
    }),
)


cc_import(
    name = "libssl_linux",
    shared_library = "libssl.so",
)


cc_import(
    name = "ssl_win",
    interface_library = "ssleay32.lib",
    shared_library = "ssleay32.dll",
)

