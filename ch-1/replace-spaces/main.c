#include <stdio.h>

int main()
{
  int c, previous_c;

  previous_c = getchar();
  while((c = getchar()) != EOF) {
    if(( c != ' ' && c != '\t' ) ||
      (previous_c != ' ' && previous_c != '\t' )) {
      putchar(previous_c);
    }
    previous_c = (c == '\t') ? ' ' : c;
  }
  putchar(previous_c);
}

