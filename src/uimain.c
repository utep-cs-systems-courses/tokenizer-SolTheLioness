#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main ()
{
  char* res = "Hello        world this is a test";
  printf ("%s\n", res);
  
  char** tokens = tokenize (res);
  int i = 0;
  while (tokens [i] != 0) {
    printf ("%s\n", tokens [i]);
    i++;
  }






  
  /* char userIn [100];
  
  while (1) {
    putchar ('>');
    fgets (userIn, 100, stdin);
    printf ("%s\n", userIn);
  }
  */
  
  return 0;
}
