#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mydef.h>

#include <heap.h>

#include <token.h>
#include <input_device.h>

/* constructor of input device */

acc_input_device INDCreate(FILE* inputFile) {
   acc_input_device aid;

   aid = (acc_input_device) HPAlloc(HPCreate(), sizeof(input_device));
   aid->inputFile = (inputFile == null_FILE) ? stdin : inputFile;

   return aid;
}

/* destructor of input device */

void INDDispose(acc_input_device aid) { HPFree(HPCreate(), (void *) aid); }

void INDSet_EOF(acc_input_device aid) { aid->eofReached = YES; }

void INDReset_EOF(acc_input_device aid) { aid->eofReached = NO; }

boolean INDEOF_Reached(acc_input_device aid) { return aid->eofReached; }

char INDGet_Char(acc_input_device aid) { return getc(aid->inputFile); }
