#
#	Makefile for building character frequency counting  program
#	

#
#	root directory
#

ROOT	= /Users/yoshie

#
#	library directory
#

LIB     = $(ROOT)/lib/C

CFILES	= 	com_args.c

OFILES	= 	com_args.o

HFILES	=	com_args.h	com_args_ds.h	mydef.h

#
#	debug flags
#

DFLAGS	= -g

#
#	include paths
#

GINC	= /Users/yoshie/include/
INCS	= -I. -I$(GINC) -I$(LIB)/heap

#
#	defines
#

DEFS	=

#
#	compile flags
#

CFLAGS	=	$(INCS)	$(DEFS)

#
#	C compiler
#

CC	= cc

RM	= rm -f

all 	:	cf

cf	:	${OFILES}

.c.o	:
		${CC} ${CFLAGS} ${DFLAGS} -c $*.c

tar	:
		touch *.c *.h
clean	:
		${RM} lst ${OFILES}  \#*\# *\~

