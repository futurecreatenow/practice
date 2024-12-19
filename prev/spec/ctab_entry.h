/* data structure for character table entry */

#ifndef CTAB_ENTRY_DS_H
#define CTAB_ENTRY_DS_H

#include <ctab_entry_ds.h>

extern acc_ctab_entry CTECreate(char);
extern void CTEFree(acc_ctab_entry);

extern boolean CTEIs_this_me(acc_ctab_entry, char);
extern void CTEInc_Freq(acc_ctab_entry);
extern int CTEFreq(acc_ctab_entry);
extern char CTEChar(acc_ctab_entry);
extern equality CTERelation(acc_ctab_entry, acc_ctab_entry, sort_key);

#endif
