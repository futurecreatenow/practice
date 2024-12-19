#ifndef CHAR_TABLE_ENTRY_H
#define CHAR_TABLE_ENTRY_H

#include <general.h>
#include <char_table_ds.h>
#include <stdio.h>

extern void CTInit(void);

extern char_table *CTCreate(void); /* singleton */
extern void CTFree(void);
extern void CTPut(acc_char_table, char c);
extern boolean CTNo_Entry(acc_char_table);
extern void CTSort(acc_char_table, sort_key);
extern void CTSetSearch(acc_char_table);
extern acc_ctab_entry CTNext(acc_char_table);

#endif
