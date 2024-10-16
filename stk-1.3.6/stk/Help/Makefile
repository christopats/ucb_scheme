#
# STk/Lib Makefile
#
#            Author: Erick Gallesio [eg@unice.fr]
#     Creation date:  2-Oct-1995 21:17  
#  Last file update: 27-Apr-1998 12:23

#include ../config.make

HLP_DIR=/usr/local/share/stk/Help

INSTALL		= /usr/bin/install -c
INSTALL_DATA	= ${INSTALL} -m 644
INSTALL_PROGRAM	= ${INSTALL}
INSTALL_SCRIPT	= ${INSTALL}

MKDIR		= mkdir
MKDIR_INST	= ${MKDIR} -m 755

lib: 

install:
	@test -d $(HLP_DIR) || ${MKDIR_INST} -p $(HLP_DIR)
	for i in *.html; do ${INSTALL_DATA} $$i $(HLP_DIR); done
	@test -d $(HLP_DIR)/Img || ${MKDIR_INST} -p $(HLP_DIR)/Img
	for i in Img/*.gif; do ${INSTALL_DATA} $$i $(HLP_DIR)/Img; done

#	../Src/test-stk -no -f make-link.stk $(HLP_DIR)

install.libs:

clean:
	rm -f index.html

distclean: clean
	rm -rf Makefile
