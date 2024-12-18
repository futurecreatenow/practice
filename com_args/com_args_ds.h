#ifndef COM_ARGS_DS_H
#define COM_ARGS_DS_H

#include <stdio.h>
#include "../mydef/mydef.h"

typedef struct com_args_{
   int noCArgs;
   string *cArgs;
   int curRemPos;
} com_args, *acc_com_args;

#endif
