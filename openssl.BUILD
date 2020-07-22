licenses(["notice"])  # Apache 2
cc_library(
    name = "openssl-lib",
    includes=["include"],
    hdrs = glob(["include/openssl/*.h"]),
    srcs = [
        "libssl.so.1.1",
        "libcrypto.so.1.1",
        ],
    copts = [
        "-I/home/twalsh/dev/openssl-1.1.1d",
        ],
    visibility = [
        "//visibility:public"
        ],
    linkstatic=True,
) 
