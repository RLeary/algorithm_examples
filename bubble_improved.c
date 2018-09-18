/* improved bubble sort - a type of exchange sort
 * This is the same as bubble.c, but with the addition of a BOOLEAN flag which
 * has been introduced to minimise the number of comparisons done, if there are
 * no exchanges, the list is sorted, saving outer loop iterations.
 * this improved version of bubble sort can be shown to be faster than the 
 * standard bubble sort by running bubble.c and bubble_improved.c with time
 */

#include "loader.h"

void bubble(char lines[][LINELEN+1], unsigned linecount);
void swap(char * first, char * second);

int main(void)
{
  char lines[MAXLINES][LINELEN+1];
  unsigned curline = 0;
  unsigned maxlines;

  /* load in the data */
  if(maxlines = load(INPUTFILE, lines), maxlines > FAIL)
    {
      bubble(lines, maxlines);
      for(curline = 0; curline < maxlines; curline++)
	{
	  printf("%s\n", lines[curline]);
	}
    }
  return EXIT_SUCCESS;
}

/* improved bubble sort */
void bubble(char lines[][LINELEN+1], unsigned linecount)
{
  unsigned inner, outer;
  BOOLEAN exchange;

  /* iterate over all the elements of the list at least once */
  for(outer = 1; outer < linecount; outer++)
    {
      /* run over the list backwards - swap any elements not in order, 
       * eventually the lower elements "bubble up" the list
       */
      exchange = FALSE;
      for(inner = linecount-1; inner >= outer; inner--)
	{
	  if(strcmp(lines[inner-1], lines[inner]) > 0)
	    {
	      swap(lines[inner-1], lines[inner]);
	      exchange = TRUE;
	    }
	}
        print_array(lines, linecount);
        /* an unsorted list will have at least one exchange per iteration. If 
         * there is no exchange, the list is sorted, so break out of the loops
	 */
        if(!exchange)
        {
            break;
        }
    }
}

void swap(char * first, char * second)
{
  char swapper[LINELEN+1];
  strcpy(swapper, first);
  strcpy(first, second);
  strcpy(second, swapper);
}
