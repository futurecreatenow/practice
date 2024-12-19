#include <out.h>

#include <char_table.h>
#include <ctab_entry.h>

#define HEADER1 " char | count"
#define HEADER2 "------|-------"

void OUTPrint_Char_Table() {
   acc_char_table act = CTCreate();
    
   acc_ctab_entry ace;

   if (CTNo_Entry(act) == NO) return;
   
   printf("%s\n%s\n", HEADER1, HEADER2);
   CTSetSearch(act);
   while ((ace = CTNext(act)) != NULL_CHAR_TABLE_ENTRY) {
      printf("  %c   |  %3d\n", CTEChar(ace), CTEFreq(ace));
   }
}
