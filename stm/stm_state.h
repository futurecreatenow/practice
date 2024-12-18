#ifndef STM_STATE_H
#define STM_STATE_H

// #include <mydef.h>
#include "../mydef/mydef.h"
// #include <stm_ds.h>
#include "stm_ds.h"

extern acc_state STTCreate_State(
   boolean, boolean,  int, acc_state (*)(acc_stm, char, acc_token));
extern boolean STTIs_Final(acc_state);
extern boolean STTIs_Initial(acc_state);
extern boolean STTIs_Error_State(acc_state);

#endif

