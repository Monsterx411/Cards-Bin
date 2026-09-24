#ifndef CARD_READER_H
#define CARD_READER_H

#include <stddef.h>
#include <stdint.h>
#include "apdu.h"

typedef struct {
    int initialized;
} CardReaderContext;

int card_reader_init(CardReaderContext *ctx);
int card_reader_connect(CardReaderContext *ctx, const char *reader_name);
int card_reader_transmit(CardReaderContext *ctx, const uint8_t *apdu, size_t apdu_len,
                         uint8_t *resp, size_t *resp_len);
int card_reader_disconnect(CardReaderContext *ctx);

#endif