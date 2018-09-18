/*genrate the factorial of a number, the same as factorial.c, but this time
 * using an iterative approach
 */
#include <stdio.h>
#include <stdlib.h>

int fact(int n);
/*for any MAXFACT larger than 15, the result will become too large for the int
 * type
 */
#define MAXFACT 10

int main(void)
{
    unsigned num;
    unsigned count;

    for(count=0; count <= MAXFACT; ++count)
    {
        num = fact(count);
        printf("the factorial of %d is %d\n", count, num);
    }
    return EXIT_SUCCESS;
}

int fact(int n)
{
    int result=1;
    unsigned count;
    for(count = 1; count <= n; ++count)
    {
        result *= count;
    }
    return result;
}
