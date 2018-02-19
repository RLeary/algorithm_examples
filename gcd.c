/* Implementation of Euclid's Algorithm to find the greatest comon divisor of
 * two integers
 */

#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);

int main(void)
{
  int i = 0, j = 0, d = 0;
  printf("Enter a number: ");
  scanf("%d", &i);
  putchar('\n');
  printf("Enter a number: ");
  scanf("%d", &j);

  printf("\nThe GCD of %d and %d is %d\n\n", i, j, gcd(i, j));

  return EXIT_SUCCESS;
}

int gcd(int i, int j)
{
  int temp;

  while(j != 0)
    {
      temp = i % j;
      i = j;
      j = temp;
    }
  return i;
}

/* Recursive implementation
 *
 * int gcd(int i, int j)
 * {
 * if(j == 0)
 *  {
 *    return i;
 *  }
 *   else
 *    {
 *      return gcd(j, i % j);
 *    }
 * }
 */

int lcd(int i, int j, int gcd)
{
  int lcm = (i * j) / gcd(i, j);
  return lcm;
}
