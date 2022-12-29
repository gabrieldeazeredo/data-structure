#include "client.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct client_t
{
    char cpf[14];
    char* name;
    int age;
    float account_balance;
};

CLIENT* client_create(char* cpf, char* name,  int age, float account_balance)
{
    CLIENT* new_client = (CLIENT*) malloc(sizeof(CLIENT));
    new_client->name = name;
    stpcpy(new_client->cpf, cpf);
    new_client->age = age;
    new_client->account_balance = account_balance;

    return new_client;
}

void client_print_info(CLIENT* client)
{
    if (client != NULL)
    {
        printf("Conta :: %s\n", client_get_name(client));
        printf("CPF :: %s\n", client_get_cpf(client));
        printf("Idade :: %d\n", client_get_age(client));
        printf("Saldo atual :: R$ %.2f\n", client_get_account_balance(client));
    }
}

char* client_get_cpf(CLIENT* client)
{
    return client->cpf;
}

char* client_get_name(CLIENT* client)
{
    return client->name;
}

int client_get_age(CLIENT* client)
{
    return client->age;
}

float client_get_account_balance(CLIENT* client)
{
    return client->account_balance;
}
void client_remove(CLIENT* client)
{
    free(client->name);
    free(client);
}

boolean cpf_greater_than(char* cpf_1, char* cpf_2)
{
    boolean isGreater = FALSE;
    
    for (int i = 13; i >= 0; i--)
    {
        if (cpf_1[i] != '-' && cpf_1[i] != '.')
        {
            if (cpf_1[i]-'0' > cpf_2[i]-'0')
            {
                isGreater = TRUE;       
            }
            else if (cpf_1[i]-'0' < cpf_2[i]-'0')
            {
                isGreater = FALSE;
            }
        }
    }
    return isGreater;
}

boolean cpf_is_equal(char* cpf_1, char* cpf_2)
{
    boolean isEqual = TRUE;
    
    for (int i = 0; i < 14; i++)
    {
        if (cpf_1[i] != cpf_2[i])
        {
            isEqual = FALSE;
            break;
        }
    }
    return isEqual;
}

void cpf_numbers_print(char *cpf)
{
    for (int i = 0; i < 14; i++)
    {
        if (cpf[i] != '-' && cpf[i] != '.')
        {
            printf("%c", cpf[i]);
        }  
    }
    printf("\n");
}