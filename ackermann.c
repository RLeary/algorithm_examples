/* Example of the Ackermann function
 */

#include <stdio.h>
#include <stdlib.h>

int ackermann(int, int);

int main(void)
{
  int i, j;
  for(i = 0; i < 10; i++)
    {
      for(j = 0; j < 10; j++)
	{
	  printf("ackerman (%d,%d) is : %d\n", i, j, ackermann(i, j));
	}
    }
  return EXIT_SUCCESS;
}

int ackermann(int m,int n)
{
  int ans;
  if(m == 0)
    {
      ans = n + 1;
    }
  else if(n == 0)
    {
      ans = ackermann(m-1, 1);
    }
  else
    {
      ans = ackermann(m-1, ackermann(m, n-1));
    }
  return ans;
}
