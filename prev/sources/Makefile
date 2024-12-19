#
#	Makefile for building character frequency counting  program
#	

CFILES	= 	main.c	char_table.c	ctab_entry.c	\
		heap.c	in.c	out.c	char.c

OFILES	= 	main.o	char_table.o	ctab_entry.o	\
		heap.o	in.o	out.o	char.o

HFILES	=	char.h	ctab_entry.h	ctab_entry_ds.h	\
		in.h	char_table.h	char_table_ds.h	\
		heap.h	heap_ds.h	out.h		\
		general.h

#
#	debug flags
#

DFLAGS	= -g

#
#	include paths
#

INCS	= -I. -I../spec -I../types

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
		${CC} ${DFLAGS} -o cf ${OFILES}

.c.o	:
		${CC} ${CFLAGS} ${DFLAGS} -c $*.c

tar	:
		touch *.c *.h
clean	:
		${RM} lst ${OFILES}  \#*\# *\~

