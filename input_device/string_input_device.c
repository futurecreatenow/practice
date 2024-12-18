#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../mydef/mydef.h"
#include "../heap/heap.h"
#include "../stm/token.h"
#include "../stm/word_stm.h"
#include "../stm/digits_stm.h"
#include "string_input_device.h"

/* constructor of input device */

acc_string_input_device SIDCreate(FILE *inputFile, int noSTMs) {
   acc_string_input_device asid;

   asid = (acc_string_input_device) HPAlloc(HPCreate(),
					    sizeof(string_input_device));

   asid->accInputDev = INDCreate(inputFile);

   WSInit(); DIGInit();
   asid->noSTMs = noSTMs;
   asid->stms = (acc_stm *) HPAlloc(HPCreate(), 2 * sizeof(acc_stm));
   asid->stms[word_STM_No] = WSCreate();
   asid->stms[dig_STM_No] = DIGCreate();

   return asid;
}

/* destructor of input device */

void SIDDispose(acc_string_input_device asid) {
   HPFree(HPCreate(), (void *) asid->accInputDev);
   HPFree(HPCreate(), (void *) asid->stms);
   HPFree(HPCreate(), (void *) asid); 
}

/* procedure to put STM */

void SIDPut_STM(acc_string_input_device asid, acc_stm s, int n) {
   asid->stms[n] = s;
}

/* function implementing logic to get token from input device */

string get_Token(
	  acc_string_input_device asid, char c, boolean *skipWS,
	  boolean *tokScanning, acc_token aTok, string tokSt,
	  int stmNo) {
   string scannedString;
   
   if (c == EOF) {
      INDSet_EOF(asid->accInputDev);
      if (skipWS) return NULLS;
      else if (*tokScanning) { TOKSet_Scanned(aTok); *tokScanning = NO; }
   }
   else if (STMIs_White_Space(asid->stms[stmNo], c)) {
      if (*skipWS) ;
      else if (tokScanning) {
	 *tokScanning = NO; *skipWS = YES;
	 TOKSet_Scanned(aTok);
      }
   }
   else if (STMIs_Alphabet(asid->stms[stmNo], c)) {
      if (*skipWS) { *tokScanning = YES; *skipWS = NO; }
      if (*tokScanning) {
	 STMTrans(asid->stms[stmNo], c);
	 if (STMIs_in_Error_State(asid->stms[stmNo]) == YES) return err_String;
      }
   }
   else
      fprintf(stderr, "Invalid character '%c', ignored.\n", c);

   if (TOKIs_Scanned(aTok) == YES) {
      if (STMIs_in_Final_State(asid->stms[stmNo]) == YES)
	 return TOKGet_Scanned_Token(aTok);
      else if (STMIs_in_Error_State(asid->stms[stmNo]) == YES)
	 return err_String;
   }

   return null_String;
}

typedef struct string_pair_ { string w, d; } string_pair, *acc_string_pair;

static string_pair sp;

acc_string_pair sp_Create(string w, string d) {
   sp.w = w; sp.d = d;
   return &sp;
}

typedef enum { EE, EN, ES, NE, NN, NS, SE, SN, SS } spp_status;

spp_status sp_Which(acc_string_pair asp) {
  if (sp.w == err_String) {
     if (sp.d == err_String) return EE;
     else if (sp.d == null_String) return EN;
     else return ES;
  }
  else if (sp.w == null_String) {
     if (sp.d == err_String) return NE;
     else if (sp.d == null_String) return NN;
     else return NS;
  }
  else {
     if (sp.d == err_String) return SE;
     else if (sp.d == null_String) return SN;
     else return SS;
  }
}

/* function to get token from input device */

string SIDGet_Token(acc_string_input_device asid) {
   char c;
   boolean skip4w = YES, skip4d = YES,
           wordScanning = NO, digitScanning = NO;
   acc_token wordTok, digTok;
   string wordSt, digSt;

   wordSt = digSt = null_String;

   WSReset(asid->stms[word_STM_No]);
   wordTok = TOKCreate();
   STMSet_Token_Scan(asid->stms[word_STM_No], wordTok);

   DIGReset(asid->stms[dig_STM_No]);
   digTok = TOKCreate();
   STMSet_Token_Scan(asid->stms[dig_STM_No], digTok);

   INDReset_EOF(asid->accInputDev);

   while (YES) {
      c = INDGet_Char(asid->accInputDev);

#     ifdef ECHO_BACK
      if (c !=EOF) putchar(c);
#     endif

      if (wordSt == null_String)
	 wordSt = get_Token(asid, c, &skip4w, &wordScanning,
			    wordTok, wordSt, word_STM_No);
       
      if (digSt == null_String)
	 digSt = get_Token(asid, c, &skip4d, &digitScanning, 
	                   digTok, digSt, dig_STM_No);

      {
	 acc_string_pair accStPair;
	 spp_status ss;

	 accStPair = sp_Create(wordSt, digSt);
	 ss = sp_Which(accStPair);

	 switch (ss) {
	 case EE: /* both error string */
	    return null_String;
	 case EN: /* word fail, digit scanning */
	    break;
	 case ES: /* word fail, digit scanned */
	    return digSt;
	 case NE: /* word scanning, digit fail */
	    break;
	 case NN: /* word scanning, digit scanning */
	    break;
	 case NS: /* word scanning, digit scanned */
	    if (skip4w == YES) return digSt; else  break;
	 case SE: /* word scanned, digit digit fail */
	    return wordSt;
	 case SN: /* word scanned, digit scanning */
	    if (skip4d == YES) return wordSt; else break;
	 case SS: /* both scanned */
	    if (strlen(wordSt) > strlen(digSt)) return wordSt;
	    else return digSt;
	 }
      }
      if (INDEOF_Reached(asid->accInputDev) == YES) return null_String;
   }
}

boolean SIDEOF_Reached(acc_string_input_device asid) {
   return INDEOF_Reached(asid->accInputDev);
}
