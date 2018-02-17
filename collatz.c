#include <stdio.h>
#include <stdlib.h>

#define MIN 1
#define INPUT_LENGTH 11
#define TEMP_STRING_LENGTH 11
#define EXTRA_CHARS 2
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILURE 0

int collatz(int, int);
int get_int(int *, int);
void clear_buffer(void);

int main(void)
{
  int n = 0, count = 0;
  printf("Enter a integer greater than 1: ");
  get_int(&n, MIN);
  
  printf("%d\n", n);
  printf("\nCollatz sequence completed in %d iterations", collatz(n, count));
  printf("\n");

  return EXIT_SUCCESS;
}

/* Collatz conjecture, for a number greater than one, if it is even, half it
 * if it is odd, triple it and add one
 */
int collatz(int n, int count)
{
  if(n == 1)
    {
      return count;
    }
  else if(n % 2 == 0)
    {
      count++;
      n = n/2;
      printf("%d ", n);
      collatz(n, count);
    }
  else
    {
      count++;
      n = (3 * n) + 1;
      printf("%d ", n);
      collatz(n, count);
    }
}

/* Read an integer from the command line
 */
int get_int(int * integer, int min)
{
  int finished = FALSE;
  char temp_string[TEMP_STRING_LENGTH + EXTRA_CHARS];
  int temp_int = 0;
  char * end;

  /* Interact with user until input is valid */
  do
    {
      /* Get input */
      fgets(temp_string, INPUT_LENGTH + EXTRA_CHARS, stdin);
      
      /* Validate input */
      if(temp_string[strlen(temp_string) - 1] != '\n')
	{
	  printf("Error: input was too long\n");
	  clear_buffer();
	}
      else
	{
	  temp_string[strlen(temp_string) - 1] = '\0';

	  temp_int = (int)strtol(temp_string, &end, 10);

	  /* Validate integer */
	  if(strcmp(end, "") != 0)
	    {
	      printf("Error: input was not numeric\n");
	    }
	  else if (temp_int <  min)
	    {
	      printf("Error: input too small\n");
	    }
	  else 
	    {
	      finished = TRUE;
	    }
	}
    }while ( finished == FALSE);

  *integer = temp_int;

  return SUCCESS;
}

/* Clears stdin */
void clear_buffer()
{
   int c;

   /* read until the end of the line or end-of-file */
   while ((c = fgetc(stdin)) != '\n' && c != EOF)
      ;

   /* clear the error and end-of-file flags */
   clearerr(stdin);
}
