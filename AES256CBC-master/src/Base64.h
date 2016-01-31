#ifndef BASE64_H_
#define BASE64_H_

//#include <windows.h>
#include <stdbool.h>
#include <string.h>

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

#define HEAP_ZERO_MEMORY 0x00000008

int Base64Encode(unsigned char **dest, const char *src, unsigned int slen);
int Base64Decode(unsigned char **dest, const char *src);
unsigned int countDecodedLength(const char *encoded);


#endif
