CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c11
SRC = src/apdu.c src/iso7816.c src/card_reader.c src/emv_reader.c src/crypto_utils.c
OBJ = $(SRC:.c=.o)
LIB = libemvreader.a

all: $(LIB)

$(LIB): $(OBJ)
	@ar rcs $(LIB) $(OBJ)

clean:
	@rm -f $(OBJ) $(LIB)