#include "card_reader.h"
#include "iso7816.h"
#include "apdu.h"

int emv_select_aid(CardReaderContext *ctx, const uint8_t *aid, size_t aid_len) {
    ApduCommand cmd = {0};
    if (iso7816_build_select_aid(aid, aid_len, &cmd) != 0) {
        return -1;
    }

    uint8_t apdu_buf[300];
    size_t apdu_len = sizeof(apdu_buf);
    if (apdu_build(&cmd, apdu_buf, &apdu_len) != 0) {
        return -1;
    }

    uint8_t resp[300];
    size_t resp_len = sizeof(resp);
    if (card_reader_transmit(ctx, apdu_buf, apdu_len, resp, &resp_len) != 0) {
        return -1;
    }

    ApduResponse parsed = {0};
    if (apdu_parse(resp, resp_len, &parsed) != 0) {
        return -1;
    }
    return (parsed.sw1 == 0x90 && parsed.sw2 == 0x00) ? 0 : -1;
}