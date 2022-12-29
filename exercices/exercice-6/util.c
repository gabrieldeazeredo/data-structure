#include "util.h"

void boolean_print(boolean bool)
{
    if(bool == TRUE)
    {
        printf("True\n");
    }
    else if (bool == FALSE)
    {
        printf("False\n");
    }
    else
    {
        printf("ERRO\n");
    }
}

char *read_line() 
{
    char *string = NULL;
    char currentInput;
    int index = 0;

    do 
    {
        currentInput = (char)getchar();
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;

        if(currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    }
    while((currentInput != '\n') && (currentInput != EOF));
    
    string[index - 1] = '\0';
    return string;
}

char *file_read_line(FILE* file) 
{
    char *string = NULL;
    char currentInput;
    int index = 0;

    do 
    {
        currentInput = (char) fgetc(file);

        if (index == 0)
        {
            if (currentInput == '\n' || currentInput == EOF)
            {
                return NULL;
            }
        }
        
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;

        if(currentInput == '\r')
        {
            currentInput = (char) fgetc(file);
        }
    } 
    while((currentInput != '\n') && (currentInput != EOF));

    string[index - 1] = '\0';
    return string;
}

void extra_line_end()
{
    char extraLineEnd;
    extraLineEnd = (char)getchar();

    if(extraLineEnd == '\r')
    {
        getchar();
    }
}
