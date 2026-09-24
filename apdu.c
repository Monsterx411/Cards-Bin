#include "apdu.h"

int apdu_build(const ApduCommand *cmd, uint8_t *out, size_t *out_len) {
    if (!cmd || !out || !out_len) {
        return -1;
    }

    size_t len = 0;
    out[len++] = cmd->cla;
    out[len++] = cmd->ins;
    out[len++] = cmd->p1;
    out[len++] = cmd->p2;
    if (cmd->lc > 0) {
        out[len++] = cmd->lc;
        for (size_t i = 0; i < cmd->lc; i++) {
            out[len++] = cmd->data[i];
        }
    }
    if (cmd->le > 0) {
        out[len++] = cmd->le;
    }

    *out_len = len;
    return 0;
}

int apdu_parse(const uint8_t *in, size_t in_len, ApduResponse *resp) {
    if (!in || in_len < 2 || !resp) {
        return -1;
    }

    resp->data_len = in_len - 2;
    for (size_t i = 0; i < resp->data_len; i++) {
        resp->data[i] = in[i];
    }
    resp->sw1 = in[in_len - 2];
    resp->sw2 = in[in_len - 1];
    return 0;
}