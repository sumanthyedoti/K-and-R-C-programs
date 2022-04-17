/**
 * Write a function reverse(s) that reverses the character string s . Use it to
 * write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAX_LENGTH 400

int getNextLine(char line[], int maxlength);
void reverse(char to[], int length);

int main()
{
  int len, max = 0, lineNo = 1;
  char line[MAX_LENGTH];

  while((len = getNextLine(line, MAX_LENGTH)) > 0) {
    if(lineNo == 1)
      printf("\n\n");
    if(len > 0) {
      reverse(line, len);
      printf("%s", line);
    }
    ++lineNo;
  }
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

void reverse(char to[], int length) {
  length = length - 2;
  for(int i = 0; i < length / 2; ++i) {
    char temp = to[i];
    to[i] = to[length - i];
    to[length - i] = temp;
  }
}
