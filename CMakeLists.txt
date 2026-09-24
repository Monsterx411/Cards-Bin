cmake_minimum_required(VERSION 3.16)
project(emvreader C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_library(emvreader
    src/apdu.c
    src/iso7816.c
    src/card_reader.c
    src/emv_reader.c
    src/crypto_utils.c
)