#include "bignumber.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int n = 0;
    char* input;
    
    scanf("%d", &n);
    extra_line_end();

    for (int i = 0; i < n; i++)
    {
        char* operation;
        BIGNUMBER* bigNumber1;
        BIGNUMBER* bigNumber2;

        input = read_line();

        operation = strtok(input, " ");

        bigNumber1 = bignumber_create(strtok(NULL, " "));
        bigNumber2 = bignumber_create(strtok(NULL, " "));

        printf("Resultado :: ");

        if (strcmp(operation, "soma") == 0)
        {
            BIGNUMBER* sumBigNumber = bignumber_sum(bigNumber1, bigNumber2);
            
            bignumber_print(sumBigNumber);
            bignumber_delete(sumBigNumber);
        }
        else if(strcmp(operation, "maior") == 0)
        {
            boolean_print(bignumber_greater_than(bigNumber1, bigNumber2));
        }
        else if (strcmp(operation, "menor") == 0)
        {
            boolean_print(bignumber_less_than(bigNumber1, bigNumber2));
        }
        else if (strcmp(operation, "igual") == 0)
        {
            boolean_print(bignumber_equal(bigNumber1, bigNumber2));
        }

        free(input);
        bignumber_delete(bigNumber1);
        bignumber_delete(bigNumber2);
    }
    
    return 0;
}  

