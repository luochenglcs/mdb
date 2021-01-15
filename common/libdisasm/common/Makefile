ARFLAGS=Urv 
CC=gcc -g $(BUILD_BITS)
CPPFLAGS += -I../common \
	-I../../common/ctf \
	-I../../uts/common/ \
	-I../../linux \
	-I../../lib/libproc/common \
	-I../../libctf \
	-DCTF_OLD_VERSIONS $(PTR32)
CPPFLAGS += -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64 \
		-D_HACK_LIBDISASM -DDIS_TEXT

LIB = ../../$(BUILD_DIR)/libdisasm.a

all: $(LIB)
	@/bin/true

$(LIB): \
	$(LIB)(libdisasm.o) \
	$(LIB)(dis_i386.o)

clean:
	-rm -f *.o $(LIB)
	
