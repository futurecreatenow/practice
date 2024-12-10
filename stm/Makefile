#
#	Makefile for building state transition program
#	

#
#	root directory
#

ROOT	= /Users/yoshie
# ROOT	= ~/research/SRA2024/C

#
#	library directory
#

LIB	= $(ROOT)/lib/C

CFILES	= 	stm.c	stm_state.c	token.c \
		word_stm.c	digits_stm.c

OFILES	= 	stm.o	stm_state.o	token.o	\
		word_stm.o	digits_stm.o

HFILES	=	stm.h	stm_ds.h	stm_state.h	token_ds.h

# LIBFILES = $(LIB)/heap/heap.o $(LIB)/com_args/com_args.o

#
#	debug flags
#

DFLAGS	= -g

#
#	include paths
#

INCS	= -I. -I$(ROOT)/include -I$(LIB)/heap -I$(LIB)/com_args -I../../include -I../spec -I../types -I../include

#
#	defines
#

# DEFS	= -DIGNORED

#
#	compile flags
#

CFLAGS	=	$(INCS)	$(DEFS)

#
#	C compiler
#

CC	= cc

RM	= rm -f

all 	:	${OFILES}

.c.o	:
		${CC} ${CFLAGS} ${DFLAGS} -c $*.c

tar	:
		touch *.c *.h
clean	:
		${RM} lst ${OFILES} gt  \#*\# *\~

