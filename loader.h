/* Heaser file for loader.c, used for loading data from text file for use by
 * the sorting programs
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL 0
#define LINELEN 80
#define EXTRACHARS 2
#define MAXLINES 50
#define INPUTFILE "words.txt"
#define FORMATLEN 5

typedef enum
  {
    FALSE,TRUE
  }BOOLEAN;

#define putline(length)\
  {\
  unsigned count;\
  for(count = 0; count < (length); ++count)\
    {\
  putchar('-');\
    }\
  putchar('\n');\
  }

unsigned load(char * fname, char lines[][LINELEN+1]);
void print_array(char[][LINELEN+1], unsigned);
unsigned find_longest(char lines[][LINELEN+1], unsigned height);
