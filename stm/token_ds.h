#include "../mydef/mydef.h"

#ifndef TOKEN_DS_H
#define TOKENDS_H

#define STM_MAX_SIZE 1024

typedef struct token_ {
   int len; char buf[STM_MAX_SIZE]; boolean scanned;
} token, *acc_token;

static const acc_token null_Token = (acc_token) NULL;

#endif
