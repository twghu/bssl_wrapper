licenses(["notice"])  # Apache 2

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "bssl_wrapper_lib",
    srcs = [
        "bssl_wrapper/bssl_wrapper.cc",
        "bssl_wrapper/bssl_hkdf.c",
        "bssl_wrapper/ossl_hkdf.c"
    ],
    hdrs = [
        "bssl_wrapper/bssl_wrapper.h",
        "include/openssl/digest.h",
        "include/openssl/hkdf.h",
    ],
    linkopts = [
        "-ldl",
    ],
    deps = [
        "@openssl//:openssl-lib",
    ],
    copts = [
        "-Iinclude"
        ]
)

