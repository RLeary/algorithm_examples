/* interpolative search - aproximimates how far along the list
 * an element is, and starts searching before and after if
 * in this example we divide the letter number of the first letter by 
 * the number of letters in the alphabet  and multiply by the number
 * of elements in the list.
 * shaker sort is used to sort the array prior to searching
 */

#include "loader.h"
#include <ctype.h>

#define NUMCHARS 26.0

char * interpol(char [][LINELEN+1], unsigned, char *);
void shake(char lines[][LINELEN+1], unsigned linecount);
void swap(char * first, char * second);

int main(void)
{
    char lines[MAXLINES][LINELEN+1];
    unsigned maxlines;
    char * found;
    char needle[LINELEN+EXTRASPACES];
    if(maxlines = load(INPUTFILE, lines), maxlines > FAIL)
    {
        shake(lines, maxlines);
        printf("Enter a search term: ");
        if(fgets(needle, LINELEN+EXTRASPACES, stdin) == NULL
            || needle[strlen(needle)-1] != '\n')
        {
            printf("Input failer\n\n");
            return EXIT_FAILURE;
        }
        needle[strlen(needle)-1]=0;
        found = interpol(lines, maxlines, needle);
        if(found)
        {
            printf("%s was found\n\n", found);
        }
        else
        {
            printf("%s was not found\n\n", needle);
        }
    }
    return EXIT_SUCCESS;
}

char * interpol(char lines[][LINELEN+1], unsigned linecount, char * needle)
{
    char start = *needle;
    unsigned curindex;
    int result=0;
    char * found=NULL;
    /* toupper and tolower convert letters case*/
    start = toupper(start);
    start -='A';
    curindex = (start/NUMCHARS) * linecount;
    do
    {
        result = strcmp(lines[curindex], needle);
        if(result == 0)
        {
            found=lines[curindex];
        }
        if(result < 0)
        {
            ++curindex;
        }
        else if(result > 0)
        {
            --curindex;
        }
    }while(curindex >0 && curindex < linecount && !found);

    return found;
}

void shake(char lines[][LINELEN+1], unsigned linecount)
{
    unsigned item;
    BOOLEAN exchange;
    do
    {
        exchange=FALSE;
        for(item=linecount-1; item > 0; item--)
        {
            printf("Item: %d\n", item);
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
    }while(exchange);
}

void swap(char * first, char * second)
{
    char swapper[LINELEN+1];
    strcpy(swapper, first);
    strcpy(first, second);
    strcpy(second, swapper);
}
