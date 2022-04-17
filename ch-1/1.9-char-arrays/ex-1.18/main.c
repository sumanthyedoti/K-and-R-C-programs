/**
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 400

int getNextLineTrimmed(char line[], int maxlength);

int main()
{
  int len, max = 0;
  char line[MAX_LENGTH];

  while((len = getNextLineTrimmed(line, MAX_LENGTH)) != EOF)
  if(len > 1) {
    printf("%s", line);
  }
  return 0;
}

int getNextLineTrimmed(char line[], int maxlength) {
  int c, i, len = 0;
  bool isTrailingSpace = true;
  for(i = 0; i < maxlength - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if(isTrailingSpace && (c != ' ' && c != '\t')) {
      isTrailingSpace = false;
    }
    if(!isTrailingSpace) {
      line[len++] = c;
    }
  }
  if(c == '\n') {
    line[len++] = c;
    if(isTrailingSpace)
      return 0;
  }
  if(c == EOF) {
    return EOF;
  }
  line[len] = '\0';
  return len;
}
