/* like self_org.c, but this time 'bumps' a successful search term up
 * the list by one
 */

#include "loader.h"

char * bump(char [][LINELEN+1], unsigned, char*);
void swap(char * first ,char * second);

int main(void)
{
    char lines[MAXLINES][LINELEN+1];
    unsigned maxlines;

    if(maxlines = load(INPUTFILE, lines), maxlines > FAIL)
    {
        char needle[LINELEN+EXTRASPACES];
        char * result;
        printf("Enter a search term: ");
        if(fgets(needle, LINELEN+EXTRASPACES, stdin) == NULL
            || needle[strlen(needle)-1] != '\n')
        {
            printf("Input failed\n\n");
            return EXIT_FAILURE;
        }
        needle[strlen(needle)-1]=0;
        result = bump(lines, maxlines, needle);
        if(result == NULL)
        {
            printf("needle not found\n\n");
            return EXIT_FAILURE;
        }
        else
        {
            printf("%s was found\n\n", result);
            print_array(lines, maxlines);
        }
    }
    return EXIT_SUCCESS;
}

char * bump(char line[][LINELEN+1], unsigned linecount, char* needle)
{
    char * result;
    unsigned count;
    for(count = 0; count < linecount; ++count)
    {
        if(!strcmp(needle, line[count]))
        {
            if(count > 0)
            {
                swap(line[count-1], line[count]);
                result = line[count-1];
            }
            else
            {
                result=line[count];
            }
            return result;
        }
    }
    return NULL;
}

void swap(char * first, char * second)
{
    char swapper[LINELEN+1];
    strcpy(swapper, first);
    strcpy(first, second);
    strcpy(second, swapper);
}
