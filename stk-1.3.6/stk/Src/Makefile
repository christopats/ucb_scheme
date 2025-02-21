#
# Makefile for STk
# 
# Copyright � 1993-1999 Erick Gallesio - I3S-CNRS/ESSI <eg@unice.fr>
# 
# Permission to use, copy, modify, distribute,and license this
# software and its documentation for any purpose is hereby granted,
# provided that existing copyright notices are retained in all
# copies and that this notice is included verbatim in any
# distributions.  No written agreement, license, or royalty fee is
# required for any of the authorized uses.
# This software is provided ``AS IS'' without express or implied
# warranty.
#
#           Author: Erick Gallesio [eg@unice.fr]
#    Creation date: ??-Sep-1993 ??:??
# Last file update:  3-Sep-1999 20:17 (eg)
#

include ../config.make

CC		= gcc
CP		= cp
XINCLUDES		= -INONE
XLIBSW		= -LNONE  -lX11 

CFLAGS		= -DMACOSX -O2 -g -O2 -DSTk_CODE -DSCM_CODE -m32 $(TK) $(OPTS) \
		  -DHAVE_CONFIG_H -I.. -I. -I../Tk/generic -I../Tk/unix \
		  -I../Tcl -I../Gmp -I../Stack $(XINCLUDES)

INSTALL         	= /usr/bin/install -c
INSTALL_DATA    	= ${INSTALL} -m 644
INSTALL_PROGRAM 	= ${INSTALL}

MKDIR		= mkdir
MKDIR_INST	= ${MKDIR} -m 755

#CFLAGS		= $(STKCFLAGS) $(MACHINE) $(DYNLOAD) $(TK) $(DFLGS) \
#		  $(OPTS) -DHAVE_CONFIG_H -I.. -I. -I../Tk/generic -I../Tk/$(FLAVOR) \
#		  -I../Tcl -I../Gmp \
#		  -I../Stack $(XINCLUDES)

#
# Add here your object ('.o') files
#
USER_OBJ		= 

#
# Scheme interpreter objects
#

SRCS		= stk.c slib.c primitives.c boolean.c char.c \
		  str.c vector.c gc.c port.c  number.c list.c symbol.c \
		  read.c print.c eval.c env.c macros.c syntax.c \
		  cont.c io.c sport.c promise.c error.c proc.c keyword.c \
		  dump.c address.c dynload.c unix.c toplevel.c argv.c \
		  extend.c signal.c trace.c module.c dummy.c \
		  stklos.c vport.c console.c

OBJS		= $(SRCS:.c=.o)

TCLSRCS		= tcl-lib.c tcl-util.c tcl-glue.c tcl-obj.c
TCLOBJ		= $(TCLSRCS:.c=.o)

TKSRCS		= tk-main.c tk-glue.c tk-util.c
TKOBJ		= $(TKSRCS:.c=.o)

TKLIB		= ../Tk/unix/libtk.a
TCLLIB		= ../Tcl/libtcl.a
EVTCLLIB		= ../Tcl/libevtcl.a
MPLIB		= ../Gmp/libgmp.a
STACKLIB		= ../Stack/libstack.a
EXTLIB		= ../Extensions/libext.a
LIBS		=  -lm $(LIB_DLD) $(LIB_MALLOC)

ALLIBS	 	= $(MPLIB) $(STACKLIB) $(TCLLIB) $(TKLIB) $(EVTCLLIB) $(EXTLIB)
SALLLIBS 		= $(MPLIB) $(STACKLIB) $(TCLLIB) $(EXTLIB)

default: 
	@echo "You must specify 'STk' or 'Snow'"

#stkvers.h: ../VERSION
#	rm -f stkvers.h
#	@echo "/* File generated. DO NOT EDIT */"	> stkvers.h
#	@echo "#define STK_VERSION \"$(VERSION)\""	>> stkvers.h

#STk: $(SRCS) stkvers.h
#	$(MAKE) stk TK="-DUSE_TK"

#Snow: $(SRCS) stkvers.h
#	$(MAKE) snow TK="-DNO_TK"

STk: $(SRCS)
	$(MAKE) stk TK="-DUSE_TK"

Snow: $(SRCS)
	$(MAKE) snow TK="-DNO_TK"

dev: 
	$(MAKE) dev-bin TK="-DUSE_TK"

tags:
	etags *.[ch] ../Tcl/*.[ch] ../Tk/*.[ch]

#toplevel.o: toplevel.c
#	$(CC) -DSTK_LIB_PATH=\"$(STK_LIBRARY)\" $(CFLAGS) $< -c

%.o: %.c stkvers.h
	$(CC) $(CFLAGS) $< -c

stk: 	userinit.o $(OBJS) $(TCLOBJ) $(TKOBJ) $(ALLIBS)
	$(CC) $(STKLDFLAGS) $(CFLAGS) -o stk userinit.o $(OBJS) $(TCLOBJ) $(TKOBJ) $(ALLIBS) \
	      $(XLIBSW) $(LIBS)

snow: 	userinit.o $(OBJS) $(TCLOBJ) $(SALLIBS)
	/bin/rm -f snow
	$(CC) $(STKLDFLAGS) $(CFLAGS) -o snow userinit.o $(OBJS) $(TCLOBJ) $(SALLLIBS)\
	       $(LIBS) 

dev-bin: userinit.o $(OBJS) $(USEROBJ) $(TCLOBJ) $(TKOBJ) $(EOBJ) $(ETKOBJ) $(SALLIBS)
	/bin/rm -f stk
	$(CC) $(STKLDFLAGS) $(CFLAGS) -o stk userinit.o $(OBJS) $(TCLOBJ) \
	      $(TKOBJ) $(EOBJ) $(ETKOBJ) $(ALLIBS) $(XLIBSW) $(LIBS)

#libstk.a: $(OBJS) $(TCLOBJ) $(TCLOBJ) $(TKOBJ) $(ETKOBJ) $(EOBJ)
#	/bin/rm -f libstk.a
#	ar rc libstk.a $(OBJS) $(TKOBJ) $(TCLOBJ) $(ETKOBJ) $(EOBJ)
#	$(RANLIB) libstk.a

libstk.a: $(OBJS) $(TCLOBJ) $(TCLOBJ) $(TKOBJ)
	/bin/rm -f libstk.a
	ar rc libstk.a $(OBJS) $(TKOBJ) $(TCLOBJ)
	$(RANLIB) libstk.a

#libsnow.a: $(OBJS) $(TCLOBJ) $(EOBJ)
#	/bin/rm -f libsnow.a
#	ar rc libsnow.a $(OBJS) $(TCLOBJ) $(EOBJ)
#	$(RANLIB) libsnow.a

libsnow.a: $(OBJS) $(TCLOBJ)
	/bin/rm -f libsnow.a
	ar rc libsnow.a $(OBJS) $(TCLOBJ)
	$(RANLIB) libsnow.a

etags:
	etags *.[ch] ../Tcl/*.[ch] ../Tk/generic/*.[ch] ../Tk/unix/*.[ch]

$(MPLIB):
	(cd ../Gmp; $(MAKE))

$(TCLLIB):
	(cd ../Tcl; $(MAKE) $(TCLLIB))

$(TKLIB): 
	(cd ../Tk; $(MAKE) $(TKLIB))

install:
	@echo "You must specify install.stk or install.snow"

install.stk: stk
	@test -d $(bindir)/arch || ${MKDIR_INST} -p $(bindir)/arch
	/bin/rm -f $(bindir)/stk
	ln -s $(execdir)/stk $(bindir)/stk 

	@test -d $(execdir) || ${MKDIR_INST} -p $(execdir)
	$(INSTALL_PROGRAM) stk $(execdir)
#	chmod 0755 $(execdir)/stk

install.stk.libs:
	@test -d $(ardir) || ${MKDIR_INST} -p $(ardir)
	$(INSTALL) libstk.a $(ardir)
	$(RANLIB) $(ardir)/libstk.a

	@test -d $(incdir) || ${MKDIR_INST} -p $(incdir)
	for i in stk.h stkvers.h tk-glue.h tcl-glue.h; do ${INSTALL_DATA} $$i $(incdir); done

#install.snow: snow
#	-if [ ! -d $(bindir) ] ; then mkdir -p $(bindir); fi
#	/bin/rm -f $(bindir)/snow-$(VERSION) $(bindir)/snow
#	ln -s $(execdir)/snow $(bindir)/snow-$(VERSION) 
#	ln -s $(execdir)/snow $(bindir)/snow 
#	-if [ ! -d $(execdir) ] ; then mkdir -p $(execdir); fi
#	$(CP) snow $(execdir)
#	chmod 0755 $(execdir)/snow

#install.snow.libs:
#	-if [ ! -d $(ardir) ] ; then mkdir -p $(ardir); fi
#	$(CP) libsnow.a $(ardir)
#	$(RANLIB) $(ardir)/libsnow.a	
#	-if [ ! -d $(incdir) ] ; then mkdir -p $(incdir); fi
#	$(CP) stk.h stkvers.h tcl-glue.h $(incdir)

#clean: 
#	rm -f *.o core stk libstk.a snow libsnow.a depends stkvers.h

clean: 
	rm -f *.o core stk stkvers.h

distclean: clean
	rm -f config.* Makefile run-stk run-snow

#depend: depends

#depends: depends
#	$(CC) -MM $(CFLAGS) $(OBJS:.o=.c) > depends

#include depends
