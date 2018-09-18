/* Selection sort
 * Finds the smallest item in the inner loop and swaps it with an element in the
 * outer loop, then moves along the outer loop. Unlike bubble sort, we have no
 * indication if the whole list is sorted, so we cannot perform the kind of
 * improvement that we can in bubble_improved.c
 * Selection divides the input list into two parts, the sublist of sorted items,
 * and the unsorted items. It finds the smallest unsorted item then places it at
 * the end of the sorted items sublist
 */

#include "loader.h"

void selection(char lines[][LINELEN+1], unsigned);
void swap(char * first, char * second);

int main(void)
{
  char lines[MAXLINES][LINELEN+1];
  unsigned curline = 0;
  unsigned maxlines;

  /* load in the data */
  /* since FAIL is also the integer 0, we can use it here for maxlines >= 1 */
  if(maxlines = load(INPUTFILE, lines), maxlines > FAIL)
    {
      selection(lines, maxlines);
      /* output the sorted data */
      for(curline = 0; curline < maxlines; curline++)
	{
	  printf("%s\n", lines[curline]);
	}
    }
  return EXIT_SUCCESS;
}

void selection(char lines[][LINELEN+1], unsigned lineouter)
{
  unsigned outer, inner, smallest;
  BOOLEAN exchange;

  for(outer = 0; outer < lineouter-1; ++outer)
    {
      /* the proportion of the list < outer has been sorted */
      exchange = FALSE;
      smallest = outer;
      /* loop through the list finding the smallest item that has not been
       * sorted 
       */
      for(inner = outer+1; inner < lineouter-1; ++inner)
	{
	  if(strcmp(lines[inner], lines[smallest]) < 0)
	    {
	      exchange = TRUE;
	      smallest = inner;
	    }
	}
      if(exchange)
	{
	  swap(lines[outer], lines[smallest]);
	}
      else
	{
	  break;
	}
      print_array(lines, lineouter);
    }
}

void swap(char * first, char * second)
{
  char swapper[LINELEN+1];
  strcpy(swapper, first);
  strcpy(first, second);
  strcpy(second, swapper);
}
