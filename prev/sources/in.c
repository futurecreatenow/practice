#include <stdio.h>

#include <in.h>

char INIn_Char() {
   char c;
   if ((c = getchar()) == EOF) return EOF; else return c;
}
