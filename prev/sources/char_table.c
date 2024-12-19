#include <stdlib.h>

#include <general.h>

#include <heap.h>
#include <ctab_entry.h>
#include <char_table.h>

/* static char_table char_Tbale; */
static acc_char_table acc_Char_Table;

/* procedure to initialize the type char_table */

void CTInit() { acc_Char_Table = NULL_CHAR_TABLE; }

/* function to create char_table instance */

char_table *CTCreate() { /* singleton */
   if (acc_Char_Table == NULL_CHAR_TABLE) {
      int y;
      acc_Char_Table =
	 (acc_char_table) HPAlloc(HPCreate(), sizeof(char_table));
      /* set initial vlues: no entry */
      for (y = 0; y < CTAB_SIZE; ++y)
	 acc_Char_Table->table[y] = NULL_CHAR_TABLE_ENTRY;
      acc_Char_Table->next = acc_Char_Table->current = 0;
   }
   return acc_Char_Table;
}

/* procedure to deallocate the char_table instance */

void CTFree() {
   int y; 

   for (y = 0; y < acc_Char_Table->next; ++y)
      HPFree(HPCreate(), (void *) acc_Char_Table->table[y]);
   HPFree(HPCreate(), (void *) acc_Char_Table);
}


/* procedure to put the given character into the table, cout up if exists 
   already */

void CTPut(acc_char_table cTab, char c) {
   int y;
   acc_ctab_entry ace;
   
   for (y = 0; y < cTab->next; ++y) {
      ace = cTab->table[y];
      if (ace == NULL_CHAR_TABLE_ENTRY) {
	 fprintf(stderr, "Null pointer access in CPut");
	 exit(NULL_POINTER_ACCESS);
      }
      else
	if (CTEIs_this_me(ace, c) == YES) {
	   CTEInc_Freq(ace); /* count up */ return;
	}
   }
   if (cTab->next >= CTAB_SIZE) {
      fprintf(stderr, "Table overflow in CPut");
      exit(TABLE_OVERFLOW);
   }
   cTab->table[cTab->next++] = CTECreate(c);
   return;
}

/* function to check if there is no entry or not */
boolean CTNo_Entry(acc_char_table act) {
   if (act->next == 0) return NO; else return YES;
}

/* procedure to sort the entry in the table: selection sort */

static void swap(acc_ctab_entry *thisTab, int l, int r) {
   acc_ctab_entry t;
   t = thisTab[l]; thisTab[l] = thisTab[r]; thisTab[r] = t;

   return;
}

void CTSort(acc_char_table cTab, sort_key key) {
   int i, j;
   
   for (i = 0; i < (cTab->next - 1); ++i)      
      for (j = i + 1; j < cTab->next; ++j) {
	if (CTERelation(cTab->table[i], cTab->table[j], key) == GREATER_THAN)
	   swap(cTab->table, i, j);
      }
}

/* procesure to set table search to the initial state */

void CTSetSearch(acc_char_table act) { act->current = 0; }

/* function to get the current vaule in the table */

acc_ctab_entry CTNext(acc_char_table act) {
   if ((act->current >= CTAB_SIZE) || (act->current >= act->next))
      return NULL_CHAR_TABLE_ENTRY;
   else
      return act->table[act->current++];
}

     
