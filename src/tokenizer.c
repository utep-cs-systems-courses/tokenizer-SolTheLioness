#include <stdio.h>

int space_char (char c) {
  if (c == '\t' || c == ' ') {
    return 1;
  }
  return 0;
}

int non_space_char (char c) {
  if (c != '\t' && c != ' ') {
    return 1;
  }
  return 0;
}

int count_words (char *str) {
  int res = 0;
  int i = 0;

  while (str [i] != '\0') {
    if (non_space_char (str [i]) && (space_char (str [i+1]) || (str [i+1] == '\0'))) {
      res++;
    }
    i++;
  }
  return res;
}

char *word_start (char *str) {
  if (!count_words (str)) {
    return '\0';
  }
  int i = 0;
  
  while (non_space_char (str [i])) {
    i++; 
  }
  if (space_char (str [i+1])) {
    while (space_char (str [i])) {
      i++;
    }
  }
  return &str [i];  
}

char *word_terminator (char *str) {
  int i = 0;

  while (non_space_char (str [i])) {
    if (str [i] == '\0') {
      return &str [i];
    }
    i++;
  }
  return &str [i];
}
