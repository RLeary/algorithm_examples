/* insertion sort - an insertion sort
 * insertion sort iterates over a list, an with each iteration it takes one 
 * element, and finds where it goes in the list, and inserts it
 */

#include "loader.h"

void insertion(char lines[][LINELEN+1], unsigned linecount);
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
      insertion(lines, maxlines);
      /* output the sorted data */
      for(curline = 0; curline < maxlines; curline++)
	{
	  printf("%s\n", lines[curline]);
	}
    }
  return EXIT_SUCCESS;
}

void insertion(char lines[][LINELEN+1], unsigned linecount)
{
  int outer, inner;
  for(outer = 1; outer < linecount; ++outer)
    {
      for(inner = outer-1; inner>= 0 && strcmp(lines[inner+1], lines[inner]) <0;
	  --inner)
	{
	  swap(lines[inner+1], lines[inner]);
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
