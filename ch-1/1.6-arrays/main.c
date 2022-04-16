#include <stdio.h>

/**
 * count the number of occurrences of each digit, alphabets, of white space,
 * characters (blank, tab, newline), and of all other characters
 */

int main()
{
  int
    c, i,
    alphabets = 0,
    nSpaces = 0,
    nSpecial = 0;
  int nDigits[10];

  for(i = 0; i < 10; ++i) {
    nDigits[i] = 0;
  }

  while((c = getchar()) != EOF)
    if(c >= '0' && c <= '9')
      ++nDigits[c - '0'];
    else if (c == ' ' || c == '\t' || c == '\n')
      ++nSpaces;
    else if ((c >= 'a' && c <= 'z') || (c >= 'A') && (c <= 'Z'))
      ++alphabets;
    else
      ++nSpecial;

  printf("\nDigits: \n");
  for(i = 0; i < 10; ++i)
    printf("  %d - %d\n", i, nDigits[i]);
  printf("Alphabets: %d\n", alphabets);
  printf("Spaces: %d\n", nSpaces);
  printf("Special Characters: %d\n", nSpecial);
}
