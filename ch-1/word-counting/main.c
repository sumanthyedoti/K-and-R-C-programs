#include <stdio.h>

short is_space(int c) {
  return c == ' ' || c == '\n' || c == '\t';
}

int main()
{
  int c, prev_c, wc;

  wc = 0;
  prev_c = getchar();
  while((c = getchar()) != EOF) {
    if((is_space(c)) && !is_space(prev_c)) {
      ++wc;
    }
    prev_c = c;
  }
  if(!is_space(prev_c)) {
    ++wc;
  }
  printf("\n%d\n", wc);
}
