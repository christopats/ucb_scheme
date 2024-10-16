#
# Copyright © 1993-1999 Erick Gallesio - I3S-CNRS/ESSI <eg@unice.fr>
# 
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
#           Author: Erick Gallesio [eg@kaolin.unice.fr]
#    Creation date:  6-Mar-1994 15:49
# Last file update:  3-Sep-1999 19:39 (eg)

include ../config.make

CC	= gcc

SH_CCFLAGS = -fpic
SH_LDFLAGS = -dynamiclib -o
SH_LOADER = gcc
SH_SUFFIX = dylib

EXAMPLES = stack.$(SH_SUFFIX) \
	   when.$(SH_SUFFIX)

CFLAGS = -DMACOSX -O2 -g -O2 -DSTk_CODE -DSCM_CODE -m32 $(SH_CCFLAGS) -DUSE_TK -DHAVE_CONFIG_H \
	-I.. -I../Tk/generic -I../Tk/unix \
	-I../Tcl -I../Src -I../Gmp $(XINCLUDES) 

##############################################################################
.SUFFIXES: .$(SH_SUFFIX) .o .c

.o.$(SH_SUFFIX): 
	$(SH_LOADER) $(SH_LDFLAGS) $*.$(SH_SUFFIX) $<
	if test -f a.out  ;then mv a.out $*.$(SH_SUFFIX); fi


##############################################################################
#all: $(EXTRA_OBJ)
#	chmod 0755 stk-genmake

all: libext.a

# Following lines are needed for weird make commands. 
# You really should use Gnu make....

#hash.$(SH_SUFFIX): 	hash.o 
#sregexp.$(SH_SUFFIX): 	sregexp.o 
#process.$(SH_SUFFIX): 	process.o 
#socket.$(SH_SUFFIX): 	socket.o 
#posix.$(SH_SUFFIX):	posix.o
#html.$(SH_SUFFIX):	html.o
#pixmap.$(SH_SUFFIX):	pixmap.o
#jpeg.$(SH_SUFFIX):	jpeg.o
#base64.$(SH_SUFFIX):	base64.o

SRCS	= base64.c hash.c html.c sregexp.c process.o \
	  posix.c pixmap.c socket.c jpeg.c

OBJS	= $(SRCS:.c=.o)

examples: $(EXAMPLES)

install:
	if test "$(EXTRA_OBJ)" != "" ; then $(CP) $(EXTRA_OBJ) $(execdir); fi

install.libs:
	-if [ ! -d $(bindir) ] ; then mkdir -p $(bindir); fi
	cp stk-genmake $(bindir)
	chmod 0755 $(bindir)/stk-genmake

%.o: %.c
	$(CC) $(CFLAGS) $< -c

libext.a:	$(OBJS)
	ar rc libext.a $(OBJS)
	ranlib libext.a

clean:
	/bin/rm -f *.o *.$(SH_SUFFIX) core *~ libext.a

distclean: clean
	/bin/rm -f Makefile config.* stk-genmake
