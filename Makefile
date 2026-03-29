CC     = gcc
CC_WIN = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -O3 -flto
LDFLAGS = -lz

ifeq ($(DEBUG), 1)
CFLAGS = -Wall -g -O0
endif

# Single source file compilation
SRC = rpx2elf.c

all: rpx2elf

rpx2elf: $(SRC) rpx2elf.h
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LDFLAGS)

win: $(SRC) rpx2elf.h
	$(CC_WIN) $(CFLAGS) -o rpx2elf.exe $(SRC) $(LDFLAGS) -static

clean:
	rm -f rpx2elf rpx2elf.exe *.o

.PHONY: all win clean