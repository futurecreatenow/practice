#ifndef TOKEN_H
#define TOKEN_H

#include "../mydef/mydef.h"

#include "token_ds.h"

extern acc_token TOKCreate();
extern void TOKDispose(acc_token);
extern void TOKPut_Char(acc_token, char);
extern void TOKSet_Scanned(acc_token);
extern boolean TOKIs_Scanned(acc_token);
extern string TOKGet_Scanned_Token(acc_token);

#endif
