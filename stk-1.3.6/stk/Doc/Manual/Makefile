# Copyright � 1994-1999 Erick Gallesio - I3S-CNRS/ESSI <eg@unice.fr>
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
#    Creation date: 21-Oct-1994 11:25
# Last file update:  3-Sep-1999 21:19 (eg)


include ../../config.make

PREFIX		= /usr/local
MANDIR		= ${PREFIX}/man
MAN1_DIR	= $(MANDIR)/man1
MANN_DIR	= $(MANDIR)/mann

INSTALL		= /usr/bin/install -c
INSTALL_DATA	= ${INSTALL} -m 644
INSTALL_PROGRAM	= ${INSTALL}
INSTALL_SCRIPT	= ${INSTALL}

MKDIR		= mkdir
MKDIR_INST	= ${MKDIR} -m 755

all: ps txt

dvi:

ps: stk.ps stk.txt man-pages.ps

txt: stk.txt

#
# Manual pages
#
man-pages.ps: 
	groff -man *.n > man-pages.ps

#
# STk man page 
#
stk.ps: stk.1
	groff -man stk.1 > stk.ps

stk.txt: stk.1
	nroff -man stk.1 > stk.txt

#
# install.man
#

install.man:
	@test -d $(MANDIR) || ${MKDIR_INST} -p $(MANDIR)
	@test -d $(MAN1_DIR) || ${MKDIR_INST} -p $(MAN1_DIR)
	${INSTALL_DATA} STk-man.macros $(MAN1_DIR)
	${INSTALL_DATA} stk.1 $(MAN1_DIR)/stk.1
	${INSTALL_DATA} stk.1 $(MAN1_DIR)/snow.1
#	ln $(MAN1_DIR)/stk.1 $(MAN1_DIR)/snow.1
	@test -d $(MANN_DIR) || ${MKDIR_INST} -p $(MANN_DIR)
	${INSTALL_DATA} STk-man.macros $(MANN_DIR)
	for  i in *.n ;do ${INSTALL_DATA} $$i $(MANN_DIR)/stk_$$i; done
#	../../Src/test-stk -no -file make-link $(MANN_DIR)

clean:
	rm -f *~ man-pages.ps

very-clean: clean
	rm -f *.ps

distclean: clean
	rm -rf Makefile
