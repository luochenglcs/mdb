ARFLAGS=Urv 
CC=gcc -g $(BUILD_BITS)
CPPFLAGS += -I../common \
	-I../../common/ctf \
	-I../../uts/common/ \
	-I../../linux \
	-I../../libdisasm/common \
	-DCTF_OLD_VERSIONS $(PTR32)
CPPFLAGS += -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64

LIB = ../../$(BUILD_DIR)/libsaveargs.a

all: $(LIB)
	@/bin/true

$(LIB): \
	$(LIB)(saveargs.o)

saveargs.o: ../amd64/saveargs.c
	$(CC) $(CPPFLAGS) -c $<
	$(AR) $(ARFLAGS) $(LIB) saveargs.o

clean:
	-rm -f *.o $(LIB)
	
