/**
 * write a program that reads a set of text lines and prints the longest
 *    while (there's another line)
 *      if (it's longer than the previous longest)
 *        (save it)
 *        (save its length)
 *    print longest line
 */

#include <stdio.h>

#define MAX_LENGTH 400

int getNextLine(char line[], int maxlength);
void copy(char to[], char from[]);

int main()
{
  int len, max = 0;
  char line[MAX_LENGTH], longest[MAX_LENGTH];

  while((len = getNextLine(line, MAX_LENGTH)) > 0)
    if(len > max) {
      max = len;
      copy(longest, line);
    }
  if(max > 0)
    printf("\nLongest line is of length: %d\n", max);
    printf("==> %s\n", longest);
  return 0;
}

int getNextLine(char line[], int maxlength) {
  int c, i;
  for(i = 0; i < maxlength - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if(c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i = 0;
  while(( to[i] = from[i] ) != '\0')
    ++i;
}
