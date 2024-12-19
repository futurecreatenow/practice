/*
   character frequency counting
*/

#include <stdio.h>
#include <in.h>
#include <char.h>
#include <heap.h>
#include <char_table.h>
#include <ctab_entry.h>
#include <out.h>

/* main function for character frequency counting */

#define PROMPT "Which key, c for character, frequency otherwise? "

int main() {
  sort_key sKey;acc_char_table act; char c;
   
   CTInit(); /* initialize the character frequency table */
   act = CTCreate();
   
   fprintf(stderr, PROMPT);
   if (getchar() == 'c') sKey = BY_CHAR; else sKey = BY_FREQ;
   
   /* count up occurrence of a character */
   while ((c = INIn_Char()) != EOF) if (CHIs_Visible(c)) CTPut(act, c);

   /* sort 'em */
   CTSort(act, sKey);
   
   /* print 'em out */
   OUTPrint_Char_Table();

   CTFree();
   
   return 0;
}
