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

CFILES	= 	input_device.c	string_input_device.c

OFILES	= 	input_device.o	string_input_device.o

HFILES	=	input_device.h		input_device_ds.h \
		string_input_device.h	string_input_device_ds.h \

LIBFILES = 	$(LIB)/heap/heap.o	$(LIB)/com_args/com_args.o \
		$(LIB)/stm/stm.o	$(LIB)/stm/stm_state.o \
		$(LIB)/stm/token.o

#
#	debug flags
#

DFLAGS	= -g

#
#	include paths
#

INCS	= -I. -I$(ROOT)/include -I$(LIB)/heap -I$(LIB)/com_args -I$(LIB)/stm -I../../include -I../spec -I../types -I../include

#
#	defines
#

DEFS	= -DECHO_BACK

#
#	compile flags
#

CFLAGS	=	$(INCS)	$(DEFS)

#
#	C compiler
#

CC	= cc

RM	= rm -f

all 	:	input_device.o	string_input_device.o

.c.o	:
		${CC} ${CFLAGS} ${DFLAGS} -c $*.c

tar	:
		touch *.c *.h
clean	:
		${RM} lst ${OFILES} gt  \#*\# *\~

