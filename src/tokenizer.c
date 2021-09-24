#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char (char c) {
  if (c == '\t' || c == ' ') {
    return 1;
  }
  return 0;
}

int non_space_char (char c) {
  if (c != '\t' && c != ' ' && c != '\0') {
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
  
  while (non_space_char (str [i]) || space_char (str [i+1])) {
    // printf ("%c\n", str [i]);
    i++; 
  }
  if (str [i+1] == '\0') {
    return '\0';
  }
  // printf ("%c\n", str [i+1]);
  return &str [i+1];  
}

char *word_terminator (char *str) {
  if (!count_words (str)) {
    return '\0';
  }
  int i = 0;

  while (non_space_char (str [i])) {
    if (str [i] == '\0') {
      return &str [i];
    }
    i++;
  }
  return &str [i];
}

int len (char *str) {
  int i = 0;
  while (str [i] != '\0') {
    i++;
  }
  return i;
}

char *copy_str (char* inStr, short len) {
  char* newStr = (char*) malloc ((len + 1) * sizeof (char));
  int i = 0;
  while (i < len) {
    newStr [i] = inStr [i];
    i++;
  }
  newStr [len + 1] = '\0';
  return newStr;
}

char **tokenize (char* str) {
  char** tokens = (char**) malloc ((count_words (str) + 1) * sizeof (char*));
  int i = 0;
  int w_len = 0;
  while (i < count_words (str)) {
    char* endWord = word_terminator (str + w_len);
    char* newWord = copy_str (str + w_len, endWord - (str + w_len));
    w_len += len (newWord) + 1;
    tokens [i] = newWord;
    i++;
    }
  
  tokens [i] = 0;
  return tokens;
}



