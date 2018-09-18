/* linear searching algorithm
 * compares strings in a list with a needle, going through each element,
 * comparing them with the needle, until a matching string is found
 * Very simple search, but not efficient
 */

#include "loader.h"

char * linear(char[][LINELEN+1], unsigned, char *);

int main(void)
{
  char lines[MAXLINES][LINELEN+1];
  unsigned maxlines;

  if(maxlines = load(INPUTFILE, lines), maxlines > FAIL)
    {
      char needle[LINELEN+EXTRACHARS];
      char * result;
      printf("Enter a search term: ");
      if(fgets(needle, LINELEN+EXTRACHARS, stdin) == NULL 
	 || needle[strlen(needle)-1] != '\n')
	{
	  printf("Input failed\n\n");
	  return EXIT_FAILURE;
	}
      needle[strlen(needle)-1] = 0;
      result = linear(lines, maxlines, needle);
      if(result == NULL)
	{
	  printf("needle not found\n\n");
	  return EXIT_FAILURE;
	}
      else
	{
	  printf("%s was found\n\n", result);
	}
    }
  return EXIT_SUCCESS;
}

char * linear(char line[][LINELEN+1], unsigned linecount, char * needle)
{
  char * result;
  unsigned count;

  for(count = 0; count < linecount; ++count)
    {
      /* strcmp() returns 0 os strings match */
      if(!strcmp(needle, line[count]))
	{
	  result = line[count];
	  return result;
	}
    }
  /* gone throught the list, needle not found, return NULL */
  return NULL;
}
