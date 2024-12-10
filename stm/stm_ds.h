#include <mydef.h>

#ifndef STM_DS_H
#define STM_DS_H

static const int max_No_States = 128;

#include <token.h>
typedef struct state_ *acc_state;

typedef struct stm_ {
   char *alphabet;
   int noAlphabets;
   char *whitespace;
   int noWhiteSpaces;
   acc_state currentState;
   int noStates;
   acc_state states[max_No_States];
   acc_token tok;
} stm, *acc_stm;

struct state_ {
   boolean isFinal, isInitial;
   int stateNo;
   acc_state (*trans)(acc_stm, char, acc_token); 
  /* acc_state (*trans)(acc_stm s, char c, acc_string_buffer sb); */
};

typedef struct state_ state;

static const acc_state Error_State = (acc_state) -1;
static const acc_stm Null_STM = (acc_stm) NULL;

static const int no_STMs = 2, word_STM_No = 0, dig_STM_No = 1;

#endif
