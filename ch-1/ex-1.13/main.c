#include <stdio.h>
#include <math.h>

/**
 * Write a program to print a histogram of the lengths of words in its input
 */

#define MAX_WORD_LENGTH 20
#define MAX_OCCURANCES 30
#define BAR_CHAR ']'

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
    i, j,
    word_length = 0,
    nWords[MAX_WORD_LENGTH] = {0};

  char c, prev_c = ' ';

  while((c = getchar()) != EOF) {
    if(!is_space(prev_c) && is_space(c)) {
      ++nWords[++word_length];
      word_length = 0;
    } else if(!is_space(prev_c) && !is_space(c)) {
      ++word_length;
    }
    prev_c = c;
  }
  //handle last charater
  if(!is_space(prev_c)) {
      ++nWords[++word_length];
  }

  printf("\nHistogram of lengths of words\n");
  printf("-------------------------------\n\n");
  for(int i = 0; i < MAX_WORD_LENGTH; ++i) {
    if(nWords[i] == 0)
      continue;
    printf("%2d | ", i);
    for(int j = 0; j < min(nWords[i], MAX_OCCURANCES); ++j) {
      printf("%c%c%c", BAR_CHAR, BAR_CHAR, BAR_CHAR);
    }
    if(nWords[i] > MAX_OCCURANCES) {
      putchar('+');
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
}
