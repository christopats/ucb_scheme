#
# STk/Lib Makefile
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
#            Author: Erick Gallesio [eg@unice.fr]
#     Creation date: ???
#  Last file update:  3-Sep-1999 20:00 (eg)


SITE_SCHEME	= NONE/lib/stk/site-scheme
STK_IMAGES	= NONE/lib/stk/1.3.6/Images
STK_STK		= NONE/lib/stk/1.3.6/STk
STK_STK_MATCH	= $(STK_STK)/Match

INSTALL		= /usr/bin/install -c
INSTALL_DATA	= ${INSTALL} -m 644
INSTALL_PROGRAM	= ${INSTALL}
INSTALL_SCRIPT	= ${INSTALL}

MKDIR		= mkdir
MKDIR_INST	= ${MKDIR} -m 755

lib: 

install:
	@test -d $(SITE_SCHEME) || ${MKDIR_INST} -p $(SITE_SCHEME)
	@test -d $(STK_IMAGES)  || ${MKDIR_INST} -p $(STK_IMAGES)
	@test -d $(STK_STK) || ${MKDIR_INST} -p $(STK_STK)
	@test -d $(STK_STK_MATCH) || ${MKDIR_INST} -p $(STK_STK_MATCH)

	for i in *.stk *.stklos STk.init; \
	do \
	  sed -e 's=/usr/local/lib/stk=$(libdir)=' \
	      -e 's=/usr/local/bin=$(bindir)=' $$i > $(STK_STK)/$$i ;\
	  chmod 0644 $(STK_STK)/$$i;\
	done

	( cd Images; for i in *; do ${INSTALL_DATA} $$i ${STK_IMAGES}; done )

	( cd Match; for i in *.scm; do ${INSTALL_DATA} $$i ${STK_STK_MATCH}; done)

install.libs:

clean:

distclean: clean
	rm -rf Makefile
