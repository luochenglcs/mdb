#
# mdb 
#

#build mdb file
MDB_DEPS = 
MDB_LDFLAGS =
MDB_CFLAGS = -g -D_HACK_LIBUMEM -D_LIBPROC_OLD -D_HACK_MDB -D_MDB_KVM -U_LIBRTLD_DB \
-D_MDB -U_MDB_KVM -U__KERNEL__ -I./include -I. -I./mdb -I./libctf -I./libdemangle/common \
-I./uts/common -I./linux -I./libproc/common -I./libdiasm/common -I./libscf/inc \
 -I./libnvpair -I./libsaveargs/common -I./modules/libumem -I./module/genunix \
-I./uts/intel -I./libdisasm/common

SRCS += \
	mdb.c \
	mdb_addrvec.c \
	mdb_argvec.c \
	mdb_callb.c \
	mdb_cmdbuf.c \
	mdb_cmds.c \
	mdb_conf.c \
	mdb_context.c \
	mdb_create.c \
	mdb_ctf.c \
	mdb_ctf_open.c \
	mdb_debug.c \
	mdb_demangle.c \
	mdb_disasm.c \
	mdb_dump.c \
	mdb_err.c \
	mdb_evset.c \
	mdb_fdio.c \
	mdb_fmt.c \
	mdb_frame.c \
	mdb_gelf.c \
	mdb_help.c \
	mdb_io.c \
	mdb_logio.c \
	mdb_list.c \
	mdb_macalias.c \
	mdb_main.c \
	mdb_memio.c \
	mdb_modapi.c \
	mdb_module.c \
	mdb_module_load.c \
	mdb_nm.c \
	mdb_nv.c \
	mdb_pipeio.c \
	mdb_print.c \
	mdb_proc.c \
	mdb_pservice.c \
	mdb_rawfile.c \
	mdb_set.c \
	mdb_shell.c \
	mdb_signal.c \
	mdb_stdlib.c \
	mdb_string.c \
	mdb_strio.c \
	mdb_tab.c \
	mdb_target.c \
	mdb_tdb.c \
	mdb_termio.c \
	mdb_typedef.c \
	mdb_umem.c \
	mdb_value.c \
	mdb_vcb.c \
	mdb_wcb.c \
	mdb_whatis.c \
	mdb_lex.c \
	mdb_grammar.c \
	proc_amd64dep.c \
	mdb_amd64util.c
	#mdb_kb_kvm.c \
	#mdb_kvm.c \
	#mdb_kproc.c \

OBJS = $(SRCS:%.c=%.o)

mdb/mdb_lex.c: mdb/mdb_grammar.h mdb/mdb_lex.l
	cd mdb; lex -t -v mdb_lex.l > mdb_lex.c; cd -
 
 mdb/mdb_grammar.h mdb/mdb_grammar.c: mdb/mdb_grammar.y
	cd mdb; \
	yacc -d -v mdb_grammar.y; \
	mv y.tab.h mdb_grammar.h; mv y.tab.c mdb_grammar.c; \
	cd -; \

mdb/proc_amd64dep.c: ../intel/mdb/proc_amd64dep.c mdb/mdb_kreg_impl.h
	cp ../intel/mdb/proc_amd64dep.c mdb/proc_amd64dep.c

mdb/mdb_amd64util.c: ../intel/mdb/mdb_amd64util.c mdb/mdb_kreg_impl.h mdb/mdb_amd64util.h
	cp ../intel/mdb/mdb_amd64util.c mdb/mdb_amd64util.c

mdb/mdb_kreg_impl.h: ../intel/mdb/mdb_kreg_impl.h mdb/mdb_kreg.h mdb/mdb_isautil.h
	cp ../intel/mdb/mdb_kreg_impl.h mdb/mdb_kreg_impl.h

mdb/mdb_isautil.h: ../intel/mdb/mdb_isautil.h mdb/mdb_amd64util.h
	cp ../intel/mdb/mdb_isautil.h mdb/mdb_isautil.h

mdb/mdb_amd64util.h: ../intel/mdb/mdb_amd64util.h
	cp ../intel/mdb/mdb_amd64util.h  mdb/mdb_amd64util.h

mdb/mdb_kreg.h: ../intel/mdb/mdb_kreg.h
	cp ../intel/mdb/mdb_kreg.h mdb/mdb_kreg.h

%.o: mdb/%.c
	$(CC) -c $(MDB_CFLAGS) $<

#build needed static libs
SUBLIBDIR += \
	libsaveargs \
	libdemangle \
	libctf \
	libproc \
	librtld \
	libdisasm \
	liblinux \
	libc

SUBLIBS = $(SUBLIBDIR:%=%.a)

libsaveargs.a:
	cd libsaveargs/common; make ; cd -

libdemangle.a:
	cd libdemangle/common; make ; cd -

libctf.a:
	cd libctf; make; cd -

libproc.a:
	cd libproc/common; make; cd -

librtld.a:
	cd librtld; make; cd -

libdisasm.a:
	cd libdisasm/common; make; cd -;

liblinux.a:
	cd liblinux; make; cd -

libc.a:
	cd libc; make; cd -

##build module libs
MODDIRS += libumem
MODLIBS = $(MODDIRS:%=%.a)

libumem.a:
	cd modules/libumem; make; cd -

PROG= mdb/mdb

all: $(PROG)
$(PROG): $(OBJS) $(SUBLIBS) $(MODLIBS)
	$(CC) -o $(PROG) $(OBJS) -ldl -lc -lm -lz -lelf -lbsd -lpthread -lncurses $(SUBLIBS) $(MODLIBS)

install: $(PROG)
	install -m 755 $(PROG) /usr/bin

clean:
	find . \( -name "*.o" -o -name "*.a" \) -exec rm -rf {} \;
	rm -rf $(PROG)
	cd mdb; \
	rm -rf mdb_amd64util.h mdb_lex.c mdb_grammar.c mdb_grammar.h y.tab.h y.tab.c\
	    y.output proc_amd64dep.c mdb_amd64util.c mdb_kreg_impl.h  mdb_isautil.h \
	    mdb_kreg.h mdb_lex.c proc_amd64dep.c y.output; \
	cd -;
