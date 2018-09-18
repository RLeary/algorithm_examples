/* Shaker sort - bidirectional bubble sort - sorts in both the forwards and
 * backwards directions as opposed to only backwards
 * uses the same improvement as bubble_improved.c, a BOOLEAN flag to check if
 * the list is sorted
 */

#include "loader.h"

void shake(char lines[][LINELEN+1], unsigned linecount);
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
      shake(lines, maxlines);
      /* output the sorted data */
      for(curline = 0; curline < maxlines; curline++)
	{
	  printf("%s\n", lines[curline]);
	}
    }
  return EXIT_SUCCESS;
}

void shake(char lines[][LINELEN+1], unsigned linecount)
{
  unsigned item;
  BOOLEAN exchange;
  do
    {
      exchange = FALSE;
      for(item = linecount-1; item > 0; item--)
	{
	  printf("item: %d\n", item);
	  if(strcmp(lines[item-1], lines[item]) > 0)
	    {
	      swap(lines[item-1], lines[item]);
	      exchange = TRUE;
	    }
	}
      for(item = 1; item < linecount; item++)
	{
	  if(strcmp(lines[item-1], lines[item]) > 0)
	    {
	      swap(lines[item-1], lines[item]);
	      exchange = TRUE;
	    }
	}
      print_array(lines, linecount);
    }while(exchange);
}


void swap(char * first, char * second)
{
  char swapper[LINELEN+1];
  strcpy(swapper, first);
  strcpy(first, second);
  strcpy(second, swapper);
}
