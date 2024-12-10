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

CFILES	= 	main.c

OFILES	= 	main.o

HFILES	=

LIBFILES = 	$(LIB)/heap/heap.o	$(LIB)/com_args/com_args.o \
		$(LIB)/stm/stm.o	$(LIB)/stm/stm_state.o \
		$(LIB)/stm/word_stm.o	$(LIB)/stm/digits_stm.o \
		$(LIB)/stm/token.o \
		$(LIB)/input_device/input_device.o \
		$(LIB)/input_device/string_input_device.o

#
#	debug flags
#

DFLAGS	= -g

#
#	include paths
#

INCS	= -I. -I$(ROOT)/include -I$(LIB)/heap -I$(LIB)/com_args -I$(LIB)/stm  -I$(LIB)/input_device -I../../include -I../spec -I../types -I../include

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

all 	:	gt

gt	:	${OFILES}
		${CC} ${DFLAGS} -o gt ${OFILES} ${LIBFILES}

.c.o	:
		${CC} ${CFLAGS} ${DFLAGS} -c $*.c

tar	:
		touch *.c *.h
clean	:
		${RM} lst ${OFILES} gt  \#*\# *\~

