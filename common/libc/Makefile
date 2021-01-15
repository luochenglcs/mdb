ARFLAGS=Urv 
CC=gcc -g $(BUILD_BITS)
CPPFLAGS += -I./inc \
	-DCTF_OLD_VERSIONS $(PTR32)
CPPFLAGS += -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64 -D_HACK_LIBC

LIB = ../libc.a

all: $(LIB)
	@/bin/true

$(LIB): \
	$(LIB)(closefrom.o) \
	$(LIB)(getexecname.o)
	#$(LIB)(priocntl.o) \
	#$(LIB)(flush.o) \

closefrom.o: port/gen/closefrom.c
	$(CC) -D__USE_LARGEFILE64 -c $(CPPFLAGS) $<

getexecname.o: port/gen/getexecname.c
	$(CC) -c $(CPPFLAGS) $<	

clean:
	-rm -f *.o
	
