/* iterative implenetation of the binary search tree */

#include "loader.h"

char * binary(char [][LINELEN+1], unsigned, char*);
void shake(char lines[][LINELEN+1], unsigned linecount);
void swap(char * first, char * second);

int main(void)
{
    char lines[MAXLINES][LINELEN+1];
    unsigned maxlines;

    if(maxlines = load(INPUTFILE, lines), maxlines > FAIL)
    {
        char needle[LINELEN+EXTRASPACES];
        char * result;
        shake(lines, maxlines);
        printf("Enter a search term: ");
        if(fgets(needle, LINELEN+EXTRASPACES, stdin) == NULL
            || needle[strlen(needle)-1] != '\n')
        {
            printf("Input failed\n\n");
            return EXIT_FAILURE;
        }
        needle[strlen(needle)-1]=0;
        result = binary(lines, maxlines, needle);
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

char * binary(char lines[][LINELEN+1], unsigned num_elements, char* needle)
{
    unsigned left, right, middle;
    int result;
    char * found=NULL;

    left=0;
    right = num_elements-1;
    do
    {
        middle=(left+right)/2;
        result = strcmp(needle, lines[middle]);
        if(result == 0)
        {
            found = lines[middle];
        }
        /*look at lhs*/
        else if(result < 0)
        {
            right = middle-1;
        }
        /*look at rhs*/
        else
        {
            left = middle+1;
        }
    }while(!found && left < right);
    return found;
}

/*shaker sort implementation - bi-directional bubble*/
void shake(char lines[][LINELEN+1], unsigned linecount)
{
    unsigned item;
    BOOLEAN exchange;
    do
    {
        exchange=FALSE;
        for(item=linecount-1; item > 0; item--)
        {
            if(strcmp(lines[item-1], lines[item]) > 0)
            {
                swap(lines[item-1], lines[item]);
                exchange=TRUE;
            }
        }
        for(item=1; item < linecount; item++)
        {
            if(strcmp(lines[item-1], lines[item]) > 0);
            {
                swap(lines[item-1], lines[item]);
                exchange=TRUE;
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
