#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main ()
{
  char* res = "    I'm       a        furry!    ";
  char** tokens = tokenize (res);
  print_tokens (tokens);
  free_tokens (tokens);
  /* char userIn [100];
  
  while (1) {
    putchar ('>');
    fgets (userIn, 100, stdin);
    printf ("%s\n", userIn);
  }
  */
  
  return 0;
}
