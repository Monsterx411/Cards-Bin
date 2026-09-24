#ifndef ISO7816_H
#define ISO7816_H

#include "apdu.h"

#define SW1_SUCCESS 0x90
#define SW2_SUCCESS 0x00

int iso7816_build_select_aid(const uint8_t *aid, size_t aid_len, ApduCommand *cmd);

#endif