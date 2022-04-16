#include <stdio.h>

#define LIMIT = 10

int power(int base, int n);

int main()
{
  for(int i = 1; i <= 10; ++i)
    printf("%2d - %4d %5d\n", i, power(2, i), power(-3, i));
  return 0;
}

int power(int base, int n) {
  int p = 1;
  for(int i = 1; i <= n; ++i)
    p = p * base;
  return p;
}
