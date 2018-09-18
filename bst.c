/* implementation of a binary search tree, using shaker sort
 * to sort the list. This uses a recursive algorithm to 
 * implenent the tree
 */

#include "loader.h"

char * binary(char[][LINELEN+1], unsigned, unsigned, char*);
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
        /* sort list with shaker sort, as a binary tree
         * can only work on sorted data
         */
        shake(lines, maxlines);
        /*get input and search*/
        printf("Enter a search term: ");
        if(fgets(needle, LINELEN+EXTRASPACES, stdin) == NULL
            || needle[strlen(needle)-1] != '\n')
        {
            printf("Input failed\n\n");
            return EXIT_FAILURE;
        }
        needle[strlen(needle)-1]=0;
        
        result = binary(lines, 0, maxlines-1, needle);
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

char * binary(char lines[][LINELEN+1], unsigned left, unsigned right,
                char* needle)
{
    /*the base case - our search indexes have overlapped*/
    if(left > right)
    {
        return NULL;
    }
    else
    {
        unsigned middle = (left+right)/2;
        int result;
        /*perform the string comparison*/
        result = strcmp(needle, lines[middle]);
        /*of we have found the target*/
        if(result == 0)
        {
            return lines[middle];
        }
        /*if the search target is lower than the current item, look
         * to the left
         */
        else if(result < 0)
        {
            return binary(lines, left, middle-1, needle);
        }
        else
        {
            /*otherwise look to the right*/
            return binary(lines, middle+1, right, needle);
        }
    }
}

void shake(char lines[][LINELEN+1], unsigned linecount)
{
    unsigned item;
    BOOLEAN exchange;
    do
    {
        exchange=FALSE;
        /*perform an upwards wave*/
        for(item=linecount-1; item>0; item--)
        {
            /*if we find an element to exchange, perform the
             * exchange and record this fact
             */
            if(strcmp(lines[item-1], lines[item]) > 0)
            {
                swap(lines[item-1], lines[item]);
                exchange=TRUE;
            }
        }
        for(item=1; item < linecount; item++)
        {
            if(strcmp(lines[item-1], lines[item]) > 0)
            {
                swap(lines[item-1], lines[item]);
                exchange=TRUE;
            }
        }
        print_array(lines, linecount);
        /* continue while the array is not completely sorted
         * a sorted list has no exchanges
         */
        }while(exchange);
}

void swap(char * first, char * second)
{
    char swapper[LINELEN+1];
    strcpy(swapper, first);
    strcpy(first, second);
    strcpy(second, swapper);
}
