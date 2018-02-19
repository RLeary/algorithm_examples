#include <stdio.h>
#include <stdlib.h>

#define MIN 0
#define INPUT_LENGTH 11
#define TEMP_STRING_LENGTH 11
#define EXTRA_CHARS 2
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILURE 0


void tower(int, char, char, char);
int get_int(int *, int);
void clear_buffer(void);

int main(void)
{
  int n;
  printf("Enter the number of disks to move: ");
  get_int(&n, MIN);
  putchar('\n');

  tower(n, 'a', 'b', 'c');

  return EXIT_SUCCESS;
}

void tower(int n, char rod_1, char rod_2, char rod_3)
{
  if(n == 1)
    {
      printf("Move disk 1 from rod %c to rod %c\n", rod_1, rod_2);
      return;
    }
  else
    {
      tower(n-1, rod_1, rod_2, rod_3);
      printf("Move disk %d from rod %c to rod %c\n", n, rod_1, rod_2);
      tower(n-1, rod_3, rod_2, rod_1);
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
