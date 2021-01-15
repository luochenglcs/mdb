ARFLAGS=Urv 
CC=gcc -g $(BUILD_BITS)
CPPFLAGS += -I../../\
	-I../../uts/common \
	-I../../linux \
	-I../../libproc/common/ \
	-I../../libctf \
	-I../../libc/inc \
	-I../../modules/genunix \
	-DCTF_OLD_VERSIONS $(PTR32)
CPPFLAGS += -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64 \
		 -D_HACK_LIBUMEM -D_HACK_MDB

LIB = ../../$(BUILD_DIR)/libumem.a

all: $(LIB) genunix.o
	ar Urv $(LIB) ../../modules/genunix/*.o

genunix.o:
	cd ../../modules/genunix; make all; cd -

$(LIB): \
	$(LIB)(leaky_subr.o) \
	$(LIB)(libumem.o) \
	$(LIB)(misc.o) \
	$(LIB)(proc_kludges.o) \
	$(LIB)(umem.o) \

clean:
	-rm -f *.o $(LIB)
