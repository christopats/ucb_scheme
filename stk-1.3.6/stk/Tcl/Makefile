# Generated automatically from Makefile.in by configure.
#
# This Makefile permits to build a subset of libtcl.a. This subset contains
# unmodified functions of the original Tcl distribution which are used in 
# the STk interpreter. Thoses functions are principally utilities functions
# such as hash tables, regexp, unix utilities
#

include ../config.make

RANLIB   = ranlib
CFLAGS   = -DSTk_CODE -DSCM_CODE -I. -I../Src  -DNO_STRERROR=1 -DNO_GETWD=1 -DNO_WAIT3=1 -DNO_UNAME=1 -DNO_DIRENT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_SYS_TIME_H=1 -DTIME_WITH_SYS_TIME=1 -DHAVE_TM_ZONE=1 -DHAVE_TM_GMTOFF=1 -DSTDC_HEADERS=1 -DUSE_DIRENT2_H=1 -DNO_SYS_ERRLIST=1 -DNO_UNION_WAIT=1 -DNEED_MATHERR=1 -Dvfork=fork -DNO_GETTOD=1 
OBJ      = panic.o tclHash.o tclGet.o regexp.o tclUtil.o  getcwd.o opendir.o strerror.o strstr.o strtol.o tmpnam.o waitpid.o strstr.o strtoul.o strtod.o strncasecmp.o
EVOBJ    = tclEvent.o tclTimer.o tclUnixNotfy.o tclUnixTime.o  tclUnixEvent.o \
           tclPreserve.o  tclNotify.o tclAsync.o
EVWINOBJ = tclEvent.o tclTimer.o tclWinNotify.o tclWinTime.o tclPreserve.o \
	   tclNotify.o tclAsync.o


all:  unix
unix: libtcl.a libevtcl.a
win:  libtcl.a libevtcl-win.a

libtcl.a: $(OBJ) 
	rm -f libtcl.a
	ar q libtcl.a $(OBJ)
	$(RANLIB) libtcl.a

libevtcl.a: $(EVOBJ) 
	rm -f libevtcl.a
	ar q libevtcl.a $(EVOBJ)
	$(RANLIB) libevtcl.a

libevtcl-win.a: $(EVWINOBJ) 
	rm -f libevtcl.a
	ar q libevtcl.a $(EVWINOBJ)
	$(RANLIB) libevtcl.a

install:

install.libs: install
	-if [ ! -d $(ardir) ] ; then mkdir -p $(ardir); fi 
	$(CP) libtcl.a $(ardir)
	$(RANLIB) $(ardir)/libtcl.a
	$(CP) libevtcl.a $(ardir)
	$(RANLIB) $(ardir)/libevtcl.a
	-if [ ! -d $(incdir) ] ; then mkdir -p $(incdir); fi
	$(CP) tcl.h tclInt.h tclRegexp.h $(incdir)

clean: 
	/bin/rm -f *.a *.o core *~

distclean: clean
	/bin/rm -f Makefile config.* tclConfig.sh

# Files which must be generated if system does not provide the function they
# implement

getcwd.o: ./compat/getcwd.c
	$(CC) -c $(CFLAGS) ./compat/getcwd.c

opendir.o: ./compat/opendir.c
	$(CC) -c $(CFLAGS) ./compat/opendir.c

strerror.o: ./compat/strerror.c
	$(CC) -c $(CFLAGS) ./compat/strerror.c

strstr.o: ./compat/strstr.c
	$(CC) -c $(CFLAGS) ./compat/strstr.c

strtod.o: ./compat/strtod.c
	$(CC) -c $(CFLAGS) ./compat/strtod.c

strtol.o: ./compat/strtol.c
	$(CC) -c $(CFLAGS) ./compat/strtol.c

strtoul.o: ./compat/strtoul.c
	$(CC) -c $(CFLAGS) ./compat/strtoul.c

tmpnam.o: ./compat/tmpnam.c
	$(CC) -c $(CFLAGS) ./compat/tmpnam.c

waitpid.o: ./compat/waitpid.c
	$(CC) -c $(CFLAGS) ./compat/waitpid.c

fixstrtod.o: ./compat/fixstrtod.c
	$(CC) -c $(CFLAGS) ./compat/fixstrtod.c

strncasecmp.o: ./compat/strncasecmp.c
	$(CC) -c $(CFLAGS) ./compat/strncasecmp.c
