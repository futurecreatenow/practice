/* data structure for character table entry */

#ifndef CTAB_ENTRY_DS
#define CTAB_ENTRY_DS

struct ctab_entry_ {
   char c; /* a character entried */
   int freq; /* its frequency */
};

typedef struct ctab_entry_ ctab_entry;
typedef ctab_entry *acc_ctab_entry;

typedef enum {BY_CHAR, BY_FREQ} sort_key;
typedef enum {LESS_THAN, EQUAL,  GREATER_THAN} equality;

#define NULL_CHAR_TABLE_ENTRY (acc_ctab_entry) 0
#define SPACE ' '

#endif
