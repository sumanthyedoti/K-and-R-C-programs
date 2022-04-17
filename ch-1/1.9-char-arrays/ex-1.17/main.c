/**
 * Write a program to print all input lines that are longer than 80 characters
 */

#include <stdio.h>

#define MAX_LINE_LENGTH 400
#define COMPARE_LENGHT 60

int getNextLine(char line[], int maxlength);
void copy(char to[], char from[]);

int main()
{
  int len, lineNo = 1;
  char line[MAX_LINE_LENGTH];

  while((len = getNextLine(line, MAX_LINE_LENGTH)) > 0) {
    if(lineNo == 1)
      printf("\nLines more than %d characters length:\n", COMPARE_LENGHT);
    if(len > COMPARE_LENGHT) {
      printf("==> %d %s", len, line);
    }
    ++lineNo;
  }
  putchar('\n');
  return 0;
}

int getNextLine(char line[], int maxlength) {
  int c, i;
  for(i = 0; i < maxlength - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if(c == EOF)
    return EOF;
  if(c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}
