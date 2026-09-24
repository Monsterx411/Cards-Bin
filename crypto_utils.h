#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H

#include <stddef.h>
#include <stdint.h>

int crypto_sha256(const uint8_t *data, size_t len, uint8_t *out, size_t out_len);

#endif