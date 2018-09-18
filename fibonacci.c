/* printf out the first MAXFIBO numbers, using a recursive algorithm
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXFIBO 45

unsigned int fibo(unsigned int);

int main(void)
{
  unsigned result, count;

  for(count = 0; count < MAXFIBO; ++count)
  {
    result = fibo(count);
    printf("fibonacci number %d is %d\n", count + 1, result);
  }
  return EXIT_SUCCESS;
}


/* recursive implementation of the fibonacci sequence. Recursive solutions can
 * look 'cleaner' than other implementaions, and can be the best way for some
 * solutions, but since each recursive call id added to the stack, they can
 * have much worse perfomance than say an iterative approach
 */
unsigned int fibo(unsigned int num)
{
  /* 0 and 1 are the base cases */
  if( num <= 0)
    {
      return 0;
    }
  if(num == 1)
    {
      return 1;
    }
  /* recursive call to calculate the sequence */
  return fibo(num-1) + fibo(num-2);
}
