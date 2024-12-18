// #include <mydef.h>
#include "../mydef/mydef.h"
// #include <heap.h>
#include "../heap/heap.h"
// #include <stm.h>
#include "stm.h"
// #include <stm_state.h>
#include "stm_state.h"

/* stm constructor */
acc_stm STMCreate() {
   acc_stm aStm;

   aStm = (acc_stm) HPAlloc(HPCreate(), sizeof(stm));
   aStm->currentState = coerce(acc_state, 0);
   aStm->noStates = 0;
   
   return aStm;
}

/* stm destructor */

void STMDispose(acc_stm aStm) {
   int y;

   for (y = 0; y < aStm->noStates; ++y)
      HPFree(HPCreate(), (void *) aStm->states[y]);

   HPFree(HPCreate(), (void *) aStm);
}

#include <stdio.h>


/* procedure to reset statetransition machine */

void STMReset(acc_stm aStm) { aStm->currentState = aStm->states[0]; }

/* procedure to memorize stm has the state */

void STMPut_State(acc_stm aStm, acc_state aSt) {
   aStm->states[aStm->noStates++] = aSt;
}

/* procedure to set buffer for scan into state transition machine */

extern void STMSet_Token_Scan(acc_stm aStm, acc_token tok) {
   aStm->tok = tok;
}

/* procedure to make transition on this stm */

void STMTrans(acc_stm aStm, char c) {
   if (STTIs_Error_State(aStm->currentState) == YES) return;
   else
      aStm->currentState = (* aStm->currentState->trans)(aStm, c, aStm->tok);
}

/* function to check if stm is in one of final states */

boolean STMIs_in_Final_State(acc_stm aStm) {
   return STTIs_Final(aStm->currentState);
}

/* function to check if stm is in the initial state */

boolean STMIs_in_Initial_State(acc_stm aStm) {
   return STTIs_Final(aStm->currentState);
}

/* function to check is stm in error state */

boolean STMIs_in_Error_State(acc_stm aStm) {
   return STTIs_Error_State(aStm->currentState);
}

/* function to get state with the given number */

acc_state STMState_has_this_no(acc_stm aStm, int n) {
   return aStm->states[n];
}

/* function to check if c is in alphabet */

boolean STMIs_Alphabet(acc_stm s, char c) {
   int y;
   for (y = 0; y < s->noAlphabets; ++y) if (c == s->alphabet[y]) return YES;
   return NO;
}

/* function to check if c is one of white space */

boolean STMIs_White_Space(acc_stm s, char c) {
   int y;
   for (y = 0; y < s->noWhiteSpaces; ++y) 
      if (c == s->whitespace[y]) return YES;
   return NO;
}

/* function to check if c is not in alphabet */

boolean STMIs_NonAlphabet(acc_stm s, char c) {
   return (!STMIs_Alphabet(s, c) && !STMIs_White_Space(s, c)) ? YES : NO;  
}
