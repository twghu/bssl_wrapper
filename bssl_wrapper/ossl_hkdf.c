/* 
* Wrapper for boring ssl hkfd.c functions 
*
* These functions where initialy created to support
* the Boring SSL equivalents.  This enables the google
* Quiche code to use OpenSSL rather than only Boring SSL.
*
* Initially based on OpenSSL version 1.1.1d.
* 
* These functions provide access to OpenSSL functions were they 
* have the same name as the BoringSSL ones in the C global space.
*/

#include <string.h>

// Exisiting OpenSSL Headers
#include <openssl/evp.h>

extern unsigned char *HKDF(const EVP_MD *evp_md,
                           const unsigned char *salt, size_t salt_len,
                           const unsigned char *key, size_t key_len,
                           const unsigned char *info, size_t info_len,
                           unsigned char *okm, size_t okm_len);

extern unsigned char *HKDF_Extract(const EVP_MD *evp_md,
                                   const unsigned char *salt, size_t salt_len,
                                   const unsigned char *key, size_t key_len,
                                   unsigned char *prk, size_t *prk_len);

extern unsigned char *HKDF_Expand(const EVP_MD *evp_md,
                                  const unsigned char *prk, size_t prk_len,
                                  const unsigned char *info, size_t info_len,
                                  unsigned char *okm, size_t okm_len);

/**
 * The method strcmp() is used in the HKDF and HKDF_expand. 
 * This may be problematic based on C/Platform implementation.  
 * The gcc strcmp converts to unsigned char * internally but
 * other implementations may not. 
 */
static int ustrcmp(unsigned char *s1, unsigned char *s2) {
   unsigned c1, c2;
   do {
     c1 = *s1++;
     c2 = *s2++;
     if ( c1 == '\0' )
       return c1 - c2;
   } while ( c1 == c2 && c2 != '\0' );
   return c1 - c2;
}

/**
 * Call the OpenSSL version of HKDF().  BoringSSL has rthe same function name.
 * This hides the BoringSSL scope enabling access to the OpenSSL implementation.
 */
int bssl_to_ossl_HKDF(uint8_t *out_key, size_t out_len, const EVP_MD *digest,
         const uint8_t *secret, size_t secret_len, const uint8_t *salt,
         size_t salt_len, const uint8_t *info, size_t info_len) {
  // https://tools.ietf.org/html/rfc5869#section-2

  unsigned char* result = HKDF(digest, salt, salt_len, secret, secret_len, info, info_len, out_key, out_len);

  // The OpenSSL version of HKDF() calls HKDF_Expand() which 
  // returns out_key when there is no error.
  return result ? strcmp((const char *)result, (const char *)out_key) == 0 : 0;
}

int bssl_to_ossl_HKDF_extract(uint8_t *out_key, size_t *out_len, const EVP_MD *digest,
                 const uint8_t *secret, size_t secret_len, const uint8_t *salt,
                 size_t salt_len) {
  // https://tools.ietf.org/html/rfc5869#section-2.2

  unsigned char *result = HKDF_Extract(digest, salt, salt_len, secret, secret_len, out_key, out_len);

  return result == NULL ? 0 : 1;
}

int bssl_to_ossl_HKDF_expand(uint8_t *out_key, size_t out_len, const EVP_MD *digest,
                const uint8_t *prk, size_t prk_len, const uint8_t *info,
                size_t info_len) {
  // https://tools.ietf.org/html/rfc5869#section-2.3

  unsigned char* result = HKDF_Expand(digest, prk, prk_len, info, info_len, out_key, out_len);

  return result ? strcmp((const char *)result, (const char *)out_key) == 0 : 0;
}
