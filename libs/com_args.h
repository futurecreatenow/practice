#ifndef COM_ARGS_H
#define COM_ARGS_H

#include <stdio.h>
#include <mydef.h>

#include <com_args_ds.h>

acc_com_args CACreate(int, string*);
void CADispose(acc_com_args);
void CAReset(acc_com_args);
void CAIncCRP(acc_com_args);
FILE* CAOpen_Current_Arg(acc_com_args, string);
FILE* CAOpen_Nth_Arg(acc_com_args, int, string);

#endif
