#ifndef CHAR_TABLE_DS
#define CHAR_TABLE_DS

#include <ctab_entry_ds.h>

#define CTAB_SIZE 1024

struct char_table_ {
   acc_ctab_entry table[CTAB_SIZE];
   int next;
   int current;
};

typedef struct char_table_ char_table, *acc_char_table;

#define NULL_CHAR_TABLE (char_table *) 0

#endif
