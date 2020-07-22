licenses(["notice"])  # Apache 2

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "bssl_wrapper_lib",
    srcs = [
        "bssl_wrapper/bssl_wrapper.cc",
        "bssl_wrapper/bssl_hkdf.c",
        "bssl_wrapper/ossl_hkdf.c",
    ],
    hdrs = [
        "bssl_wrapper/bssl_wrapper.h",
#        "//include:bssl_ossl_interface",
        "openssl/digest.h",
        "openssl/hkdf.h",
    ],
    linkopts = [
        "-ldl",
    ],
    deps = [
        "@openssl//:openssl-lib",
    ],
)

# Header files for external use
cc_library(
    name = "bssl_ossl_interface",
    hdrs = [
        "openssl/digest.h",
        "openssl/hkdf.h",
    ],
)

