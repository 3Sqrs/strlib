#include <_string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trimString(const char *str) {
  size_t len = strlen(str);
  size_t new_len = 1;

  for (int char_i = 0; char_i < len; char_i++) {
    if (isspace(str[char_i])) {
      continue;
    }

    new_len++;
  }

  char *buf = malloc(new_len);
  if (!buf) {
    return NULL;
  }

  size_t buf_i = 0;
  for (size_t i = 0; i < len; i++) {
    unsigned char c = (unsigned char)str[i];
    if (isspace(c)) {
      continue;
    }

    buf[buf_i++] = str[i];
  }

  buf[new_len] = '\0';
  return buf;
}

int main(void) {
  char str[64];

  printf("Hi, What's your name?\n> ");

  if (fgets(str, sizeof(str), stdin) == NULL) {
    printf("Fail get your str.\n");
    return 1;
  }

  char *new_str = trimString(str);
  if (new_str) {
    printf("Trimed str: %s", new_str);
    free(new_str);
  }

  return 0;
}
