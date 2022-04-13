#include <stdio.h>

/* Write a program that prints its input one word per line */

_Bool is_space(int c) {
  return c == ' ' || c == '\n' || c == '\t' || c == EOF;
}

int main()
{
  int c, prev_c;

  prev_c = getchar();
  printf("\n");
  while((c = getchar()) != EOF) {
    if(!is_space(prev_c))
      putchar(prev_c);
    if(is_space(prev_c) && !is_space(c))
      printf("\n");
    prev_c = c;
  }
  if(!is_space(prev_c)) {
    putchar(prev_c);
  }
}

