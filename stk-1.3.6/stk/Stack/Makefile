#
# Makefile for the libstack library
#
# Copyright © 1997-1999 Erick Gallesio - I3S-CNRS/ESSI <eg@unice.fr>
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
#    Creation date: 27-Sep-1997 20:02
# Last file update:  3-Sep-1999 21:05 (eg)
#

CC		= gcc
CFLAGS		= -DMACOSX -O2 -g -O2 -DSTk_CODE -DSCM_CODE -m32 
RANLIB		= ranlib

INSTALL		= /usr/bin/install -c
INSTALL_DATA	= ${INSTALL} -m 644
INSTALL_PROGRAM	= ${INSTALL}
INSTALL_SCRIPT	= ${INSTALL}

MKDIR		= mkdir
MKDIR_INST	= ${MKDIR} -m 755

all: libstack.a 

libstack.a: libstack.o 
	/bin/rm -f libstack.a
	ar cqv libstack.a libstack.o 
	${RANLIB} libstack.a

install: libstack.a

libstack.o: libstack-UNKNOWN_ARCH.c libstack.h
	${CC} ${CFLAGS} -c libstack-UNKNOWN_ARCH.c -o $@

install.libs:
	@test -d /usr/local/Libs || ${MKDIR_INST} -p /usr/local/Libs
	${INSTALL_DATA} libstack.a /usr/local/Libs

test: testlib
	./testlib | uniq -c

testlib: test.o libstack.a 
	$(CC) -o testlib test.o libstack.a 

clean: 
	rm -f *.o *~ config.* libstack.a testlib

distclean: clean
	rm -f libstack.c lowstack.s lowstack.c Makefile libstack.h conftest.c
