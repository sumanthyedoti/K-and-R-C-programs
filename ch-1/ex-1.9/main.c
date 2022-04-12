#include <stdio.h>

/* Write a program to copy its input to its output, replacing each string of one or
 * more blanks by a single blank. */

int main()
{
  int c, prev_c;

  prev_c = getchar();
  while((c = getchar()) != EOF) {
    if(( c != ' ' && c != '\t' ) ||
      (prev_c != ' ' && prev_c != '\t' )) {
      putchar(prev_c);
      prev_c = (c == '\t') ? ' ' : c;
    }
  }
  putchar(prev_c);
}

