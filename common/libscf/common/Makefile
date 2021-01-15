ARFLAGS=Urv 
CC=gcc -g $(BUILD_BITS)
CPPFLAGS += -I../common \
	-I../inc \
	-I../../uts/common/ \
	-I../../libnvpair \
	-I../../linux \
	-DCTF_OLD_VERSIONS $(PTR32)
CPPFLAGS += -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64

LIB = ../../$(BUILD_DIR)/libscf.a

all: $(LIB)
	@/bin/true

$(LIB): \
	$(LIB)(midlevel.o)

clean:
	-rm -f *.o
	