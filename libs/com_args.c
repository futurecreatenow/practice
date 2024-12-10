#ifndef COM_ARGS_H
#define COM_ARGS_H

#include <stdio.h>
#include <mydef.h>

#include <heap.h>
#include <com_args_ds.h>

/* constructor for command arguments */

acc_com_args CACreate(int n, string* a) {
   acc_com_args ac;

   ac = (acc_com_args) HPAlloc(HPCreate(), sizeof(com_args));
   ac->noCArgs = n; ac->cArgs = a;
   ac->curRemPos = 0;

   return ac;
}

/* destructor for command arguments */

void CADispose(acc_com_args aca) { HPFree(HPCreate(), (void *) aca); }

/* porcedure to reset current remarkable position */

void CAReset(acc_com_args aca) {
  aca->curRemPos = 0;
}

/* procedure to increment current remarkable position */

void CAIncCRP(acc_com_args aca) { ++aca->curRemPos; }

/* function to get FILE access to current remarkable argument */

FILE* CAOpen_Current_Arg(acc_com_args aca, string mode) {
   FILE* f;

   if (aca->curRemPos > aca->noCArgs) return NULL_FILE;
   else {
      f = fopen(aca->cArgs[aca->curRemPos++], mode);
   }
   return f;
}

FILE* CAOpen_Nth_Arg(acc_com_args aca, int n, string mode) {
   FILE* f;

   if (n > aca->noCArgs) return NULL_FILE;
   else f = fopen(aca->cArgs[n], mode);

   return f;
}

#endif
