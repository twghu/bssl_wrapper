/* 
* Wrapper for boring ssl hkfd.c functions 
*
* These functions where initialy created to support
* the Boring SSL equivalents.  This enables the google
* Quiche code to use OpenSSL rather than only Boring SSL.
*
* Initially based on OpenSSL version 1.1.1d.
*/

// Wrapper headers
// As of 1.1.1d this file did not exist in the openssl source tree.
#include "openssl/hkdf.h"

// Exisiting OpenSSL Headers
#include <openssl/evp.h>

// bssl and ossl have same HKDF() function name.  Aliasing with a wrapper.
extern int bssl_to_ossl_HKDF(uint8_t *out_key, size_t out_len, const EVP_MD *digest,
         const uint8_t *secret, size_t secret_len, const uint8_t *salt,
         size_t salt_len, const uint8_t *info, size_t info_len);
// Aliasing other HKDF functions to ensure no implicit function errors on compile.
extern int bssl_to_ossl_HKDF_extract(uint8_t *out_key, size_t *out_len, const EVP_MD *digest,
                 const uint8_t *secret, size_t secret_len, const uint8_t *salt,
                 size_t salt_len);
extern int bssl_to_ossl_HKDF_expand(uint8_t *out_key, size_t out_len, const EVP_MD *digest,
                const uint8_t *prk, size_t prk_len, const uint8_t *info,
                size_t info_len);

int HKDF(uint8_t *out_key, size_t out_len, const EVP_MD *digest,
         const uint8_t *secret, size_t secret_len, const uint8_t *salt,
         size_t salt_len, const uint8_t *info, size_t info_len) {
  // https://tools.ietf.org/html/rfc5869#section-2

  return bssl_to_ossl_HKDF(out_key, out_len, digest, secret, secret_len, salt, salt_len, info, info_len);
}

int HKDF_extract(uint8_t *out_key, size_t *out_len, const EVP_MD *digest,
                 const uint8_t *secret, size_t secret_len, const uint8_t *salt,
                 size_t salt_len) {
  // https://tools.ietf.org/html/rfc5869#section-2.2

  return bssl_to_ossl_HKDF_extract(out_key, out_len, digest, secret, secret_len, salt, salt_len);
}

int HKDF_expand(uint8_t *out_key, size_t out_len, const EVP_MD *digest,
                const uint8_t *prk, size_t prk_len, const uint8_t *info,
                size_t info_len) {
  // https://tools.ietf.org/html/rfc5869#section-2.3

  return bssl_to_ossl_HKDF_expand(out_key, out_len, digest, prk, prk_len, info, info_len);
}
