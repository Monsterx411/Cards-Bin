#ifndef APDU_H
#define APDU_H

#include <stddef.h>
#include <stdint.h>

#define APDU_MAX_DATA 255

typedef struct {
    uint8_t cla;
    uint8_t ins;
    uint8_t p1;
    uint8_t p2;
    uint8_t lc;
    uint8_t data[APDU_MAX_DATA];
    uint8_t le;
} ApduCommand;

typedef struct {
    uint8_t data[APDU_MAX_DATA];
    size_t data_len;
    uint8_t sw1;
    uint8_t sw2;
} ApduResponse;

int apdu_build(const ApduCommand *cmd, uint8_t *out, size_t *out_len);
int apdu_parse(const uint8_t *in, size_t in_len, ApduResponse *resp);

#endif