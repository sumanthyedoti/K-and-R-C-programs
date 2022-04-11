#include <stdio.h>

/** print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */

#define LOWER 0
#define FOR 0
#define UPPER 300
#define STEP 20

float fahr_to_celsius(int);

int main()
{
  int fahr;

  printf("Convertion table for Fahrenheit to Celsius\n");
  printf("------------------------------------------\n");
  for(fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    printf("%4.0d  %.2f\n", fahr, fahr_to_celsius(fahr));
  }

}

float fahr_to_celsius(int f) {
  return (f - 32) * (5.0 / 9.0);
}
