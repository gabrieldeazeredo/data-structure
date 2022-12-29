#ifndef CLIENT_H
#define CLIENT_H

#include "util.h"

typedef struct client_t CLIENT;

CLIENT *client_create(char *cpf, char *name, int age, float account_balance);
void client_remove(CLIENT *client);

void client_print_info(CLIENT *client);

char *client_get_cpf(CLIENT *client);
char *client_get_name(CLIENT *client);
int client_get_age(CLIENT *client);
float client_get_account_balance(CLIENT *client);

void cpf_numbers_print(char *cpf);
boolean cpf_greater_than(char *cpf_1, char *cpf_2);
boolean cpf_is_equal(char *cpf_1, char *cpf_2);

#endif // CLIENT_H