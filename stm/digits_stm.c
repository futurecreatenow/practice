#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <mydef.h>

#include <token.h>

#include <stm.h>
#include <stm_state.h>

#include <word_stm.h>

typedef acc_stm acc_digits_stm;

static acc_digits_stm thisDigStm;

static acc_state s0_2_s1(acc_digits_stm s, char c, acc_token tok) {
   if (isdigit(c) == 0) { /* no digit */
      /*
      if (STMIs_in_Final_State(s) == YES) {
	 TOKSet_Scanned(tok); return s->currentState;
      }
      else {
	 fprintf(stderr, "Bad character '%c': event must be DIGIT in s0.", c);
#        ifndef IGNORE
	 exit(ERROR);
#        else
	 fprintf(stderr, " Ignored.\n");
#        endif
      }
      */
      return Error_State;
   }
   else {
      TOKPut_Char(tok, c);
      return STMState_has_this_no(s, 1);
   }
}

static const char comma = ',';

static acc_state s1_2_sx(acc_digits_stm s, char c, acc_token tok) {
   if (isdigit(c)) { /*  digit s1->s1 */
      TOKPut_Char(tok, c); return STMState_has_this_no(s, 1);
   }
   else if (c == comma) { /* ',' s1->s2*/
      TOKPut_Char(tok, c); return STMState_has_this_no(s, 2);
   }
   else {
      if (STMIs_in_Final_State(s) == YES) {
	 TOKSet_Scanned(tok); return s->currentState;
      }
      else /* {
	 fprintf(stderr, "Internal Error: bad char '%c' in s1.", c);
 	 exit(ERROR); return STMState_has_this_no(s, 1); // dummy
      } */
	 return Error_State;
   }
}

acc_state s2_2_s1(acc_digits_stm s, char c, acc_token tok) {
   if (isdigit(c)) { /* digit s2->s1 */
      TOKPut_Char(tok, c); return STMState_has_this_no(s, 1);
   }
   else {
      if (STMIs_in_Final_State(s) == YES) {
	 TOKSet_Scanned(tok); return s->currentState;
      }
      else /* {
	 fprintf(stderr, "Bad character '%c' in s2.", c);
#        ifndef IGNORED
	 exit(ERROR);
#        else
	 fprintf(stderr, "Ignored.\n");
#        endif
	 return STMState_has_this_no(s, 2);
	 } */
	 return Error_State;
   }
}

static char
   alphabets[] = {
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ','
   },
   white_Spaces[] = {
      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
      'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
      'U', 'V', 'W', 'X', 'Y', 'Z',
      'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
      'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
      'u', 'v', 'w', 'x', 'y', 'z',
      '-', '\'',
      ' ', '\t', '\n', '.', ':', ';', '!'
   };

static const int no_Alphabets = 11, no_White_Spaces = 61;

acc_word_stm DIGCreate() {
   if (thisDigStm == Null_STM) {
      acc_state s0, s1, s2;
      
      thisDigStm = STMCreate();

      thisDigStm->alphabet = alphabets;
      thisDigStm->noAlphabets = no_Alphabets;   
      thisDigStm->whitespace = white_Spaces; 
      thisDigStm->noWhiteSpaces = no_White_Spaces;

      s0 = STTCreate_State(NO, YES, 0, s0_2_s1);
      STMPut_State(thisDigStm, s0);

      s1 = STTCreate_State(YES, NO, 1, s1_2_sx);
      STMPut_State(thisDigStm, s1);

      s2 = STTCreate_State(NO, NO, 2, s2_2_s1);
      STMPut_State(thisDigStm, s2);
   }
   return thisDigStm;
}

void DIGInit() { thisDigStm = Null_STM; }

void DIGReset(acc_stm thisDSTM) { STMReset(thisDigStm); }
