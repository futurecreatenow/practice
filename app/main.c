#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <heap.h>

#include <token.h>
#include <word_stm.h>
#include <digits_stm.h>
#include <com_args.h>
#include <string_input_device.h>


static boolean eofReached;

int main(int noComArgs, string ComArgs[]) {
   string w;
   acc_com_args aca;
   string words[128];
   int nw = 0, y;
   acc_string_input_device inDev;
   FILE *inFile;
   acc_stm wordSTM, digSTM;

   static const int no_STMs = 2, word_STM_No = 0, dig_STM_No = 1;

   HPInit();
   aca = CACreate(noComArgs, ComArgs);
   inFile = CAOpen_Nth_Arg(aca, 1, READMODE);
   inDev = SIDCreate(inFile, no_STMs);
   SIDPut_STM(inDev, WSCreate(), word_STM_No);
   SIDPut_STM(inDev, DIGCreate(), dig_STM_No);
   
   while ((w = SIDGet_Token(inDev)) != NULLS) {
      words[nw++] = w;
      if (SIDEOF_Reached(inDev) == YES) break;
   }

   {
      int n = 0;

      printf("\nWords Scanned\n");
      for (y = 0; y < nw; ++y) {
	 printf("%10s:%d ", words[y], (int) strlen(words[y]));
	 if (n == 4) {
	    n = 0; printf("\n");
	 }
	 else ++n;
      
	 HPFree(HPCreate(), (void *) words[y]);
      }
      printf("\n");
   }
   fclose(inFile);
}
