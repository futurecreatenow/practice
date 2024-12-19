#include <char.h>

#define SPACE ' '
#define TILDE '~'

boolean CHIs_Visible(char c) {
  if ((SPACE <= c) && (c <= TILDE)) return YES; else return NO;
}
