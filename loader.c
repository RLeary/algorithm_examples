/* loader.c, functions used in loading data from a text file, used by the
 * sorting programs
 */

#include "loader.h"

/* char lines[][LINELEN+1] is for the format of the input text, a text file
 * containing strings on separate lines. Other formats would require a different
 * method to load. Data is loaded into a 2d array
 */
unsigned load(char * fname, char lines[][LINELEN+1])
{
  FILE * fpread = fopen(fname, "r");
  char line[LINELEN + EXTRACHARS];
  unsigned curline = 0;

  if(!fpread)
    {
      return FAIL;
    }
  while(fgets(line, LINELEN + EXTRACHARS, fpread))
    {
      if(line[strlen(line)-1] != '\n')
	{
	  fprintf(stderr, "Error: line too long in input file\n\n");
	  /* anything opened MUST be closed to prevent memory leaks */
	  fclose(fpread);
	  return FAIL;
	}
      line[strlen(line)-1] = 0;
      strcpy(lines[curline++], line);
      if(curline >= MAXLINES)
	{
	  fprintf(stderr, "Maximum lines reached\n\n");
	  fclose(fpread);
	  return FAIL;
	}
    }
  fclose(fpread);
  return curline;
}

void print_array(char lines[][LINELEN+1], unsigned height)
{
  unsigned width, count;
  width = find_longest(lines, height);

  putchar('\n');
  putline(width + 2);
  for(count = 0; count < height; ++count)
    {
      char format[FORMATLEN];
      sprintf(format, "%%%ds", width);
      putchar('|');
      printf(format, lines[count]);
      printf("|\n");
    }
  putline(width + 2);
  printf("\n\n\n");
}

unsigned find_longest(char lines[][LINELEN+1], unsigned height)
{
  unsigned longest = 0, count;

  for(count = 0; count < height; ++count)
    {
      unsigned length = strlen(lines[count]);
      if(length > longest)
	{
	  longest = length;
	}
    }
  return longest;
}
