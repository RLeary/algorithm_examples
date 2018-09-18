/* prints out the first MAXFIBO fibonacci numbers, using an iterative 
 * algorithm. This approach is much faster than the recursive implementation
 * in fibonacci.c, where the recureive call really slow the program down once
 * it gets into the 30's
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

unsigned int fibo(unsigned int num)
{
  unsigned count, first = 0, second = 1, next;
  for(count = 0; count < num; ++count)
    {
      if(count <= 1)
	  {
	    next = count;
	  }
      else
	  {
	    next = first + second;
	    first = second;
	    second = next;
	  }
    }
    return next;
  
}
