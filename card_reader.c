#include "card_reader.h"
#include <string.h>

int card_reader_init(CardReaderContext *ctx) {
    if (!ctx) {
        return -1;
    }
    ctx->initialized = 1;
    return 0;
}

int card_reader_connect(CardReaderContext *ctx, const char *reader_name) {
    (void)reader_name;
    if (!ctx || !ctx->initialized) {
        return -1;
    }
    return 0;
}

int card_reader_transmit(CardReaderContext *ctx, const uint8_t *apdu, size_t apdu_len,
                         uint8_t *resp, size_t *resp_len) {
    (void)apdu;
    (void)apdu_len;
    if (!ctx || !ctx->initialized || !resp || !resp_len || *resp_len < 2) {
        return -1;
    }

    resp[0] = 0x90;
    resp[1] = 0x00;
    *resp_len = 2;
    return 0;
}

int card_reader_disconnect(CardReaderContext *ctx) {
    if (!ctx) {
        return -1;
    }
    memset(ctx, 0, sizeof(CardReaderContext));
    return 0;
}