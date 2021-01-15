ARFLAGS=Urv 
CC=gcc -g $(BUILD_BITS)
CPPFLAGS += -I../../\
	-I../../uts/common \
	-I../../libproc/common/ \
	-I../../linux \
	-I../../libctf \
	-I../../libc/inc \
	-DCTF_OLD_VERSIONS $(PTR32)
CPPFLAGS += -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64 \
		-D_HACK_MDB

SRCS += \
	kgrep.c \
	leaky.c \
	dist.c

OBJS = $(SRCS:%.c=%.o)

all: $(OBJS)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $<

clean:
	-rm -f *.o
	
