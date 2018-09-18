/* searching alorithm
 * uses a linear search, but optimises the search by moving
 * any successful search terms to the top of the list, making
 * it quicker to find terms that are searched for most often
 * there is a downside to this, as all elements get moved down
 * which could be a lot of work
 */

#include "loader.h"

char * self_org(char[][LINELEN+1], unsigned, char*);
void swap(char * first, char * second);
void move_to_front(char[][LINELEN+1], unsigned);

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
        result = self_org(lines, maxlines, needle);
        if(result == NULL)
        {
            printf("needle not ofund\n\n");
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

/*find the needle, then move it to the front of the list
 */
char * self_org(char lines[][LINELEN+1], unsigned linecount, char * needle)
{
    char * result;
    unsigned count;
    for(count = 0; count < linecount; ++count)
    {
        if(!strcmp(needle, lines[count]))
        {
            move_to_front(lines, count);
            result = lines[0];
            return result;
        }
    }
    return NULL;
}

/* moves the found string to the front of the list, then
 * moves all the other strings down on place backwards
 */
void move_to_front(char lines[][LINELEN+1], unsigned index)
{
    char newline[LINELEN+1];
    unsigned backcount;
    /* copy the needle string into a newline by parameter, which
     * will then be moves to the front of the list
     */
    strcpy(newline, lines[index]);
    for(backcount=index; backcount>0; --backcount)
    {
        strcpy(lines[backcount], lines[backcount-1]);
    }
    strcpy(lines[0], newline);
}

void swap(char * first, char * second)
{
    char swapper[LINELEN+1];
    strcpy(swapper, first);
    strcpy(first, second);
    strcpy(second, swapper);
}
