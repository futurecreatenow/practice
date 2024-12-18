#ifndef STM_H
#define STM_H

// #include <mydef.h>
#include "../mydef/mydef.h"
// #include <stm_ds.h>
#include "stm_ds.h"

extern acc_stm STMCreate();
extern void STMDispose(acc_stm);
extern void STMPut_State(acc_stm, acc_state);
extern void STMReset(acc_stm);
extern void STMSet_Token_Scan(acc_stm, acc_token);
extern void  STMTrans(acc_stm, char);
extern boolean STMIs_in_Final_State(acc_stm);
extern boolean STMIs_in_Initial_State(acc_stm);
extern boolean STMIs_in_Error_State(acc_stm);
extern acc_state STMState_has_this_no(acc_stm, int);
extern boolean STMIs_Alphabet(acc_stm, char);
extern boolean STMIs_White_Space(acc_stm, char);
extern boolean STMIs_NonAlphabet(acc_stm, char);

#endif
