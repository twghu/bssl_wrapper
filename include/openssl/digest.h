/* 
* Wrapper header for Boring SSL digest.c functions 
*
* These functions where initialy created to support
* the Boring SSL equivalents.  This enables the google
* Quiche code to use OpenSSL rather than only Boring SSL.
*
* Initially based on OpenSSL version 1.1.1d, digest.h did
* not exist in the OpenSSL version.
*/

#ifndef OPENSSL_HEADER_DIGEST_H
#define OPENSSL_HEADER_DIGEST_H

#include <openssl/ossl_typ.h>

#if defined(__cplusplus)
extern "C" {
#endif


// Digest functions.
//
// An EVP_MD abstracts the details of a specific hash function allowing code to
// deal with the concept of a "hash function" without needing to know exactly
// which hash function it is.


// Hash algorithms.
//
// The following functions return |EVP_MD| objects that implement the named hash
// function.

OPENSSL_EXPORT const EVP_MD *EVP_sha256(void);

#if !defined(BORINGSSL_NO_CXX)
extern "C++" {
}  // extern C++
#endif

#endif  // OPENSSL_HEADER_DIGEST_H
