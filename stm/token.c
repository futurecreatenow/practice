#include <string.h>
// #include <mydef.h>
// #include <heap.h>
#include "../mydef/mydef.h"
#include "../heap/heap.h"
// #include <token.h>
#include "token.h"

acc_token TOKCreate() {
   acc_token t;

   t = (acc_token) HPAlloc(HPCreate(), sizeof(token));
   t->len = 0; t->scanned = NO;

   return t;
}

void TOKDispose(acc_token tok) { HPFree(HPCreate(), (void *) tok); }

void TOKPut_Char(acc_token tok, char c) { tok->buf[tok->len++] = c; }

void TOKSet_Scanned(acc_token tok) { tok->scanned = YES; }

boolean TOKIs_Scanned(acc_token tok) { return tok->scanned; }

string TOKGet_Scanned_Token(acc_token tok) {
   string s;
   
   tok->buf[tok->len++] = NULLC;
   s = (string) HPAlloc(HPCreate(), tok->len);
   strcpy(s, tok->buf);

   return s;
}


