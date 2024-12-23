/*
	mydef.h

	general definition for my own C programs

					05/09/86	Masami Noro
                                        20240913 rev.   Masami Noro   */

#ifndef MYDEF_H
#define MYDEF_H

#define coerce(XTYPE, OBJECT) (XTYPE) OBJECT

#define NULL_POINTER_ACCESS -77
typedef enum {NO, YES} boolean;
typedef enum {FAIL,  SUCCESS} result;
typedef enum {FALSE, TRUE} bool;

#define SUCCESS 1
#define FAIL 0

#ifndef NULL
#define NULL 0
#endif
#ifndef NULLS
#define NULLS coerce(char *, 0)
#endif
#ifndef NULLV
#define NULLV coerce(void *, 0)
#endif
#ifndef NULLC
#define NULLC coerce(char, 0)
#endif
#define	NULLIF coerce(int (*)(), 0)
#define BS coerce(char, 0x08)
#define CR coerce(char, 0x0d)
#define LF coerce(char, 0x0a)
#define NL '\n'
#ifndef BLANK
#define BLANK coerce(char, 0x20)
#endif
#define TABC '\011'
#define ESC coerce(char, 0x1b)
#define FF  coerce(char, 0x0c)

#define BLANKS "                                                                                                 "

#define NULL_FILE (FILE *)0
#ifdef NT
#define READMODE "rb"
#define WRITEMODE "wb"
#define APPENDMODE "ab"
#else
#define READMODE "r"
#define WRITEMODE "w"
#define APPENDMODE "a"
#endif

#define _DEC 10
#define _HEX 16
#define _BIN 2
#define _OCT 8


#ifndef ERROR
#define ERROR -1
#endif
#define NONERROR 0

#define STRFMT "%s\n"

typedef char *string;


#ifndef OFF
typedef int flag;

#define OFF	0
#define ON	1
#endif

typedef void *any_type;

#endif
