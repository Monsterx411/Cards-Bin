#include "iso7816.h"

int iso7816_build_select_aid(const uint8_t *aid, size_t aid_len, ApduCommand *cmd) {
    if (!aid || !cmd || aid_len == 0 || aid_len > APDU_MAX_DATA) {
        return -1;
    }

    cmd->cla = 0x00;
    cmd->ins = 0xA4;
    cmd->p1 = 0x04;
    cmd->p2 = 0x00;
    cmd->lc = (uint8_t)aid_len;
    for (size_t i = 0; i < aid_len; i++) {
        cmd->data[i] = aid[i];
    }
    cmd->le = 0x00;
    return 0;
}