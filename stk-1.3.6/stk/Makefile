#
# Toplevel Makefile for STk
#
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
# Last file update:  3-Sep-1999 20:03 (eg)
#

#SHELL		= /bin/sh
#MACHTYPE		= Darwin-23.6.0-arm64
PREFIX 		= /usr/local
machine		= arm64
os		= Darwin

VERSION		= 1.3.6

INSTALL         = /usr/bin/install -c
INSTALL_DATA    = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}

MKDIR		= @MKDIR@
MKDIR_INST	= ${MKDIR} -m 755

STKDIR		= $(PREFIX)/lib/stk
libdir 		= $(stkdir)/$(VERSION)
execdir		= $(PREFIX)/bin/arch/$(os)/$(machine)
confdir		= $(execdir)/Config
ardir		= $(execdir)/Libs
incdir		= $(PREFIX)/include

all: unix

unix:  tcl-dir mp-dir stack-dir tk-dir ext-dir src-dir stklos-dir
win:   tcl-dir mp-dir stack-dir tk-dir ext-dir snow-dir src-dir stklos-dir

config.make: Makefile
	@/bin/rm -f config.make
	@echo "# Common startup for all Makefiles"	>  config.make
	@echo "# This file is automatically generated"	>> config.make
	@echo ""					>> config.make
	@echo "VERSION		= 1.3.6"	>> config.make
	@echo "machine		= $(machine)"		>> config.make
	@echo "os		= $(os)"		>> config.make
	@echo "prefix		= $(PREFIX)"		>> config.make
	@echo "CC		= gcc"			>> config.make
	@cat ./paths					>> config.make

tcl-dir: config.make
	@(echo "make Tcl"; cd Tcl; $(MAKE))

tk-dir: config.make tcl-dir
	@(echo "make Tk"; cd Tk/unix; $(MAKE))

mp-dir: config.make
	@(echo "make Gmp"; cd Gmp; $(MAKE))

stack-dir: config.make
	@(echo "make Stack"; cd Stack; $(MAKE))

src-dir: config.make
	@(echo "make Src"; cd Src; $(MAKE) stk TK="-DUSE_TK")

# No longer building snow
#snow-dir: config.make
#	@(echo "make Snow"; cd Snow; $(MAKE) snow TK="-DNO_TK")

stklos-dir: config.make
	@(echo "make STklos"; cd STklos; $(MAKE) stklos)	

ext-dir: config.make
	@(echo "Make Extensions"; cd Extensions; $(MAKE) all)

doc: config.make
	@(echo "Make Documentation"; cd Doc; $(MAKE) all)

dvi: config.make
	@(echo "Make Documentation(dvi)"; cd Doc; $(MAKE) dvi)

demos:
	/bin/sh -c "(cd Demos; ../Src/test-stk -f S-scape README.html)"

install:
	(cd Tcl;     	$(MAKE) install)
	(cd Tk/unix;   	$(MAKE) install)
	(cd Gmp;		$(MAKE) install)
	(cd Src;     	$(MAKE) install.stk)
#	(cd Snow;     	$(MAKE) install.snow)
	(cd Lib;     	$(MAKE) install)
	(cd STklos;  	$(MAKE) install)
	(cd Extensions; 	$(MAKE) install)
	(cd Demos;   	$(MAKE) install)
	(cd Help;		$(MAKE) install)
	(cd Doc;		$(MAKE) install)
	(cd Stack;	$(MAKE) install)
	@echo "Installation completed."

install.libs:
	@test -d $(confdir) || ${MKDIR_INST} -p $(confdir)
	${INSTALL_DATA} config.make $(confdir)

	@test -d $(incdir) || ${MKDIR_INST} -p $(incdir)
	/bin/rm -f $(stkdir)/include

	(cd $(stkdir) ; ln -s $(VERSION)/include ./include)

	(cd Tcl;     	$(MAKE) install.libs prefix=$(PREFIX))
	(cd Tk;      	$(MAKE) install.libs prefix=$(PREFIX))
	(cd Gmp;		$(MAKE) install.libs prefix=$(PREFIX))
	(cd Src;     	$(MAKE) install.stk.libs root=$(root))
#	(cd Snow;     	$(MAKE) install.snow.libs root=$(root))
	(cd Stack;	$(MAKE) install.libs root=$(root))
	chmod 0755 $(confdir) $(ardir) $(confdir)/* $(ardir)/*
	@echo ""
	@echo "Full installation completed."

binary-release: install install.man
	(cd $(PREFIX)/lib; \
	tar cvfz /tmp//STk-$(VERSION)-$(MACHINE).tar.gz stk/$(VERSION)/$(MACHINE))
	@echo "The release is in the file  /tmp/STk-$(VERSION)-$(MACHINE).tar.gz"
	@echo "Don't forget to create the file STk-$(VERSION)-$(MACHINE).README"
	@echo "to describe the content of your archive (a template is given in"
	@echo "the file BINARY-DISTRIB"

common-release: 
	(cd $(PREFIX)/lib; \
	 tar cvfz /tmp/STk-$(VERSION)-common.tar.gz stk/$(VERSION)/Help   \
						    stk/$(VERSION)/STk    \
						    stk/$(VERSION)/demos  \
						    stk/$(VERSION)/images \
						    stk/$(VERSION)/images \
						    stk/$(VERSION)/man    \
						    stk/man)
	@echo "Termin�. Le fichier est dans /tmp/STk-$(VERSION)-common.tar.gz"

clean-before:
	@if [ -d $(PREFIX)/lib/stk ]; \
	then \
	  echo "*** WARNING:"; \
	  echo "*** A previous version of STk has already been installed in"; \
	  echo "*** directory '$(stkdir)'. It is not a problem since"; \
	  echo "*** several versions can coexist now in this directory"; \
	  echo "*** However, if you are short in place, or if you don't use "; \
	  echo "*** a multi architecture file system, cleaning may be a good"; \
	  echo "*** thing to do."; \
	fi

	@if [ -d $(PREFIX)/lib/stk/$(VERSION) ]; \
	then \
	  echo "*** WARNING:"; \
	  echo "*** This STk version ($(VERSION)) has already been installed "; \
	  echo "*** on this machine. "; \
	  echo "*** (Waiting 10s) " ; \
	  sleep 10;\
	  echo "Deleting previous installation"; \

	  /bin/rm -rf $(stkdir)/$(VERSION); \
	fi

install.man:
	(cd Doc;		$(MAKE) install.man)

clean:
	(cd Tcl;    	$(MAKE) clean)
	(cd Tk/unix;   	$(MAKE) clean)
	(cd Gmp;     	$(MAKE) clean)
	(cd Stack;     	$(MAKE) clean)
	(cd Src;    	$(MAKE) clean)
#	(cd Snow;    	$(MAKE) clean)
	(cd STklos; 	$(MAKE) clean)
	(cd Extensions;	$(MAKE) clean)
	(cd Help;		$(MAKE) clean)
	(cd Doc;		$(MAKE) clean)

	/bin/rm -f core *~

distclean: clean
	(cd Tcl;    	$(MAKE) distclean)
	(cd Tk/unix;  	$(MAKE) distclean)
	(cd Gmp;     	$(MAKE) distclean)
	(cd Stack;     	$(MAKE) distclean)
	(cd Src;    	$(MAKE) distclean)
	(cd Extensions;	$(MAKE) distclean)
	(cd STklos; 	$(MAKE) distclean)
	(cd Help;		$(MAKE) distclean)
	(cd Doc;		$(MAKE) distclean)
	(cd Lib;		$(MAKE) distclean)
	(cd Demos;	$(MAKE) distclean)

	rm -f Utils/STk.spec Makefile configure.lineno config.status \
	config.log config.make config.h
