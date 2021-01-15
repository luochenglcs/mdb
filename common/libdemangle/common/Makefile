ARFLAGS=Urv 
CC=gcc -g $(BUILD_BITS)
CPPFLAGS += -I../common \
	-I../../common/ctf \
	-I../../uts/common/ \
	-I../../linux \
	-I../../lib/libproc/common \
	-I../../libctf \
	-DCTF_OLD_VERSIONS $(PTR32)
CPPFLAGS += -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64

LIB = ../../$(BUILD_DIR)/libdemangle.a

all: $(LIB)
	@/bin/true

$(LIB): \
	$(LIB)(cxx.o) \
	$(LIB)(cxx_util.o) \
	$(LIB)(demangle.o) \
	$(LIB)(str.o) \
	$(LIB)(strview.o) \
	$(LIB)(util.o)
	#(LIB)(rust.o)

clean:
	-rm -f *.o
	
