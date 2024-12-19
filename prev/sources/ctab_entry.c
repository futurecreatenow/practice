/* operations for character table entry */

#include <stdio.h>

#include <general.h>
#include <heap.h>
#include <ctab_entry_ds.h>

acc_ctab_entry CTECreate(char c) {
   acc_ctab_entry ace; heap *accHeap = HPCreate();

   ace = (acc_ctab_entry) HPAlloc(accHeap, sizeof(ctab_entry));
   ace->c = c; ace->freq = 1;

   return ace;
}

void CTEFree(acc_ctab_entry ace) { HPFree(HPCreate(), (void *) ace); }

boolean CTEIs_this_me(acc_ctab_entry ace, char c) {
   if (ace->c == c) return YES; else return NO;
}

void CTEInc_Freq(acc_ctab_entry ace) { ++ace->freq; }

int CTEFreq(acc_ctab_entry ace) { return ace->freq; }
char CTEChar(acc_ctab_entry ace) { return ace->c; }

equality CTERelation(acc_ctab_entry l, acc_ctab_entry r, sort_key cc) {
  int rl, rr;
   
   switch (cc) {
   case BY_CHAR:
      rl = l->c < r->c;
      rr = l->c > r->c;
      break;
   case BY_FREQ:
      rl = l->freq < r->freq;
      rr = l->freq > r->freq;
   }
   
   if (rl == 1) return LESS_THAN;
   else if (rr == 1) return GREATER_THAN;
   else return EQUAL;
}
