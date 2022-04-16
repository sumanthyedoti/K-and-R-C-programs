#include <stdio.h>
#include <math.h>

/**
 * Write a program to print a histogram of the lengths of words in its input
 */

#define NUM_OF_CHARS 256
#define MAX_OCCURANCES 30
#define BAR_CHAR '*'

_Bool is_space(int c) {
  return c == ' ' || c == '\n' || c == '\t' || c == EOF;
}

int min(int num1, int num2)
{
    return (num1 > num2 ) ? num2 : num1;
}

int main()
{
  int
    nChars[256] = {0};

  char c;

  while((c = getchar()) != EOF) {
    if(!is_space(c)) {
      ++nChars[c];
    }
  }

  printf("\n\nHistogram of the frequencies of characters\n");
  printf("-------------------------------\n\n");
  for(int i = 0; i < 256; ++i) {
    if(nChars[i] == 0)
      continue;
    printf("%2c | ", i);
    for(int j = 0; j < min(nChars[i], MAX_OCCURANCES); ++j) {
      printf("%c%c%c", '-', '-', BAR_CHAR);
    }
    if(nChars[i] > MAX_OCCURANCES) {
      printf("--");
    }
    putchar('\n');
  }
  printf("%3c", ' ');
  for(int i = 0; i <= MAX_OCCURANCES; ++i) {
    printf("---");
  }
  printf("\n%5c", ' ');
  for(int i = 1; i <= MAX_OCCURANCES; ++i) {
    printf("%3d", i);
  }
  putchar('\n');
  return 0;
}
