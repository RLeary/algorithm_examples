/* Find the least common multiple of two integers. Uses GCD to find LCM
 */

#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);
int lcm(int, int, int);

int main(void)
{
  int i = 0, j = 0, d = 0, l = 0;
  printf("Enter a number: ");
  scanf("%d", &i);
  putchar('\n');
  printf("Enter a number: ");
  scanf("%d", &j);

  printf("\nThe LCM of %d and %d is %d\n\n", i, j, lcm(i, j, gcd(i, j)));

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

int lcm(int i, int j, int gcd)
{
  int lcm = (i * j) / gcd;
  return lcm;
}
