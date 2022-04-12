#include <stdio.h>

/* Write a program to count blanks, tabs, and newlines */

int main()
{
  int c, blanks, nl, tabs;

  blanks = nl = tabs = 0;
  while((c = getchar()) != EOF) {
    if(c == '\n')
      ++nl;
    else if(c == ' ')
      ++blanks;
    else if(c == '\t')
      ++tabs;
  }
  printf("\n");
  printf("Blanks: %d\n", blanks);
  printf("Tabs: %d\n", tabs);
  printf("New Lines: %d\n", nl);
}

