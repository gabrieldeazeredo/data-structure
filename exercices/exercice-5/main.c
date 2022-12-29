#include "client-tree.h"
#include "client.h"
#include "util.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

CLIENT* input_into_client(char* input);

int main()
{
    int n = 0;
    char* input = NULL;
    char input_char;
    CLIENT_TREE* client_tree = client_tree_create();
    CLIENT* client = NULL;

    scanf("%d", &n);
    extra_line_end();

    for (int i = 0; i < n; i++)
    {
        input = read_line();

        client = input_into_client(input);
        client_tree_insert_client(client_tree, client);
        free(input);
    }
    
    scanf("%c", &input_char);
    extra_line_end();

    input = read_line();

    if (input_char == 'I')
    {        
        client_tree_insert_client(client_tree, input_into_client(input));
        
        printf("Preorder\n");
        client_tree_pre_order(client_tree); 
    }
    else if (input_char == 'B')
    {
        client = client_tree_search_client(client_tree, input);

        if (client == NULL)
        {
            printf("Pessoa nao encontrada.");
        }
        else
        {
            client_print_info(client);
        }
    }
    else if (input_char == 'R')
    {
        client_tree_remove_client(client_tree, input);

        printf("Preorder\n");
        client_tree_pre_order(client_tree); 
    }
    printf("\n");

    free(input);
    client_tree_delete_tree(&client_tree);

    return 0;
}  

CLIENT* input_into_client(char* input)
{
    char cpf[14];
    int age = 0;
    float account_balance = 0;
    char* tempString;

    tempString = strtok(input, ";");
    strcpy(cpf, tempString);
    
    tempString = strtok(NULL, ";");

    char* name = (char*) malloc(sizeof(char)*strlen(tempString)+1);
    strcpy(name, tempString);

    tempString = strtok(NULL, ";");
    age = atoi(tempString);

    tempString = strtok(NULL, ";");
    account_balance = atof(tempString);

    CLIENT* client = client_create(cpf, name, age, account_balance); 

    return client;
}