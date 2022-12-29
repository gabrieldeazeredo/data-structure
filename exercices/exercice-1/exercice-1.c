#include <stdio.h>

void calculate_change(int *change, int *oneReal, int *fifthCents, int *twentyFiveCents, int *tenCents, int *fiveCents, int *oneCent);

int main()
{
    int change = 0; 
    int oneReal = 0, fifthCents = 0, twentyFiveCents = 0, tenCents = 0, fiveCents = 0, oneCent = 0;

    scanf("%i", &change);

    calculate_change(&change, &oneReal, &fifthCents, &twentyFiveCents, &tenCents, &fiveCents, &oneCent);

    printf("O valor consiste em %d moedas de 1 real\n", oneReal);
    printf("O valor consiste em %d moedas de 50 centavos\n", fifthCents);
    printf("O valor consiste em %d moedas de 25 centavos\n", twentyFiveCents);
    printf("O valor consiste em %d moedas de 10 centavos\n", tenCents);
    printf("O valor consiste em %d moedas de 5 centavos\n", fiveCents);
    printf("O valor consiste em %d moedas de 1 centavo\n", oneCent);

    return 0;
}

void calculate_change(int *change, int *oneReal, int *fifthCents, int *twentyFiveCents, int *tenCents, int *fiveCents, int *oneCent)
{
    
    *oneReal = *change/100;
    *change = *change - *oneReal*100;
    
    *fifthCents = *change/50;
    *change = *change - *fifthCents*50;
     
    *twentyFiveCents = *change/25;
    *change = *change - *twentyFiveCents*25;
    
    *tenCents = *change/10;
    *change = *change - *tenCents*10;
    
    *fiveCents = *change/5;
    *change = *change - *fiveCents*5;
    
    *oneCent = *change;
    
}
