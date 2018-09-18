/* This program is an example of bubble sort, a type of exchange sort - where a 
 * list is iterated over once forwards, and on each iteration it is iterated
 * over backwards, swapping any elements tha are out of order, causing them 
 * to "bubble" up the list
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
  /* since FAIL is also the integer 0, we can use it here for maxlines >= 1 */
  if(maxlines = load(INPUTFILE, lines), maxlines > FAIL)
    {
      bubble(lines, maxlines);
      /* output the sorted data */
      for(curline = 0; curline < maxlines; curline++)
	{
	  printf("%s\n", lines[curline]);
	}
    }
  return EXIT_SUCCESS;
}

void bubble(char lines[][LINELEN+1], unsigned linecount)
{
  unsigned inner, outer;
  /* iterate over all the elements of th elist at least once */
  for(outer = 1; outer < linecount; outer++)
    {
      /* run over the list backwards - swap any elements that are not sorted, 
       * eventually the lowe elements "bubble up" the list
       */
      for(inner = linecount-1; inner >= outer; inner--)
	{
	  if(strcmp(lines[inner-1], lines[inner]) > 0)
	    {
	      swap(lines[inner-1], lines[inner]);
	    }
	}
      print_array(lines, linecount);
    }
}

void swap(char * first, char * second)
{
  char swapper[LINELEN+1];
  strcpy(swapper, first);
  strcpy(first, second);
  strcpy(second, swapper);
}
