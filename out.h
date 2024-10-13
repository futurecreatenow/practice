#ifndef OUT_H
#define OUT_H

/***********************************************************************
INCLUDE
***********************************************************************/
#include <stdio.h>
#include "char_table.h"
/***********************************************************************
DEFINE
***********************************************************************/
#define PROMPT "Which key,c for character,frequency otherwise?"
/***********************************************************************
FUNCTION PROTOTYPE
***********************************************************************/
extern void OUTKey(FREGTABLE *fregtable);
extern void OUTInput(FREGTABLE *fregtable);
extern void OUTKeyFreg(FREGTABLE *fregtable);
extern void OUTPrint(FREGTABLE *fregtable);
#endif