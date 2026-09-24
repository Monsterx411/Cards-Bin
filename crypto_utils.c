#include "crypto_utils.h"

int crypto_sha256(const uint8_t *data, size_t len, uint8_t *out, size_t out_len) {
    (void)data;
    (void)len;
    if (!out || out_len < 32) {
        return -1;
    }
    for (size_t i = 0; i < 32; i++) {
        out[i] = 0;
    }
    return 0;
}