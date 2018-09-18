/* quicksort implementation
 * quicksort picks an element in a list as a pivot, and moves anything smaller
 * to the left, and anything larger to the right. Quicksort is then called
 * recursively on these partitions until the list is sorted.
 */

#include "loader.h"

void quicksort(char lines[][LINELEN+1], unsigned left, unsigned right);
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
      quicksort(lines, 0, maxlines-1);
      /* output the sorted data */
      for(curline = 0; curline < maxlines; curline++)
	{
	  printf("%s\n", lines[curline]);
	}
    }
  return EXIT_SUCCESS;
}

void quicksort(char lines[][LINELEN+1], unsigned left, unsigned right)
{
  /* store the pivor index */
  unsigned mid = left+right/2;
  /* temporarily store the left and right index so we can iterate over the array
   */
  unsigned lcount = left;
  unsigned rcount = right;
  /* base case - all partitions have been sorted */
  if(mid > right || mid < left)
    {
      return;
    }
  swap(lines[mid], lines[left]);
  ++lcount;
  /* do the sorting */
  do
    {
      /* skip over all leftward elements less than the partition */
      while((strcmp(lines[lcount], lines[left]) < 0) && (lcount <= right))
	{
	  ++lcount;
	}
      /* skip over all rightwards elements greater than the partition */
      while((strcmp(lines[rcount], lines[left]) > 0) && (rcount > left))
	{
	  --rcount;
	}
      /* if there are elements that need to be shifted */
      if(lcount < rcount)
	{
	  swap(lines[lcount], lines[rcount]);
	  ++lcount;
	  --rcount;
	}
    }while(lcount < rcount);
  swap(lines[left], lines[mid]);
  print_array(lines, 10);
  if(left < rcount)
    {
      quicksort(lines, left, mid - 1);
    }
  if(lcount < right)
    {
      quicksort(lines, mid + 1, right);
    }
}

void swap(char * first, char * second)
{
  char swapper[LINELEN+1];
  strcpy(swapper, first);
  strcpy(first, second);
  strcpy(second, swapper);
}
