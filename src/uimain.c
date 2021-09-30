#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 101
int userInterface (char user_input [MAX], List *hist);

int main ()
{
  char user_input [MAX];
  user_input [100] = '\0';
  List* hist = init_history ();
  
  printf ("\nEnter some text, no more than 100 characters long. Enter '~' to see past history, or '~<number> to access a specific portion of history. Enter '/quit' to quit.\n\n");

  userInterface (user_input, hist);
  return 0;
}


int userInterface (char user_input [MAX], List* hist) {
  char** tokens;
  while (1) {
    printf ("%s", "> ");
    fgets (user_input, MAX, stdin);
    if (user_input [0] == '/' && user_input [1] == 'q' && user_input [2] == 'u' && user_input [3] == 'i' && user_input [4] == 't') {
      return 0;
    } else if (user_input [0] == '~') {
      if (user_input [1] != '\n') {
	printf ("%s\n", get_history (hist, user_input [1] - '0'));
      } else {
	print_history (hist);
      }
    } else {
      add_history (hist, user_input);
      tokens = tokenize (user_input);
      printf ("Number of words: %d\n", count_words (user_input));
      print_tokens (tokens);
    }
  }
}
