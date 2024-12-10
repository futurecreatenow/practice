#include <mydef.h>

#include <heap.h>

#include <stm_state.h>

#include <stdio.h>

acc_state STTCreate_State(boolean isFin, boolean isIni,  int stNo,
			  acc_state (*tMeth)(acc_stm, char, acc_token)) {
   acc_state aSt;

   aSt = (acc_state) HPAlloc(HPCreate(), sizeof(state));
   aSt->isFinal = isFin; aSt->isInitial = isIni; aSt->stateNo = stNo;
   aSt->trans = tMeth;

   return aSt;
}

boolean STTIs_Final(acc_state aSt) { return aSt->isFinal; }

boolean STTIs_Initial(acc_state aSt) {return aSt->isInitial; }

boolean STTIs_Error_State(acc_state aSt) { return aSt == Error_State; }
