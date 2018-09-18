/* generate the factorial of a number using a recursive algorithm 
 * due to using int types, this program can only handle up to 15!
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXFACT 10

int fact(int);

int main(void)
{
  unsigned num, count;

  for(count = 0; count <= MAXFACT; ++count)
    {
      num = fact(count);
      printf("the factorial of %d is %d\n", count, num);
    }
  return EXIT_SUCCESS;
}

int fact(int n)
{
  /* base case - 0! = 1 */
  if(n <=1 )
    {
      return 1;
    }
  else
    {
      /* n! = n!(n-1)! */
      int result = n * fact(n-1);
      return result;
    }
}
