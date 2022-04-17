#include <stdio.h>
#include <stdbool.h>

/**
 * write a program that reads a set of text lines and prints the longest
 *
 *  while (there's another line)
 *    if (it's longer than the previous longest)
 *      (save it)
 *      (save its length)
 *  print longest line
 */


#define MAX_LENGTH 400

int getNextTrimmedLine(char line[], int maxlength);

int main()
{
  int len, max = 0;
  char line[MAX_LENGTH];

  while((len = getNextTrimmedLine(line, MAX_LENGTH)) != EOF)
  if(len > 1) {
    printf("%s", line);
  }
  return 0;
}

int getNextTrimmedLine(char line[], int maxlength) {
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
