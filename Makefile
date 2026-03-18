CC     = gcc
CC_WIN = x86_64-w64-mingw32-gcc
CFLAGS = -Wall

ifeq ($(DEBUG), 1)
CFLAGS+=-g -O0
else
CFLAGS+=-O2
endif

OBJS     = rpx2elf.o utils.o
OBJS_WIN = rpx2elf_win.o utils_win.o

all: rpx2elf

rpx2elf: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) -lz

rpx2elf.o: rpx2elf.c
	$(CC) $(CFLAGS) -c -o $@ $<

utils.o: utils.c
	$(CC) $(CFLAGS) -c -o $@ $<

win: $(OBJS_WIN)
	$(CC_WIN) $(CFLAGS) -o rpx2elf.exe $(OBJS_WIN) $(LDFLAGS) -lz

rpx2elf_win.o: rpx2elf.c
	$(CC_WIN) $(CFLAGS) -c -o $@ $<

utils_win.o: utils.c
	$(CC_WIN) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(OBJS_WIN) rpx2elf rpx2elf.exe

.PHONY: all win clean