#include "bignumber.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

static void insert_node_on_start(BIGNUMBER* bigNumber, int value);
static void insert_node_on_end(BIGNUMBER* bigNumber, int value);
static void removing_leading_zeros(char* input);
static void print_node(NODE* node);
static void sum_nodes(BIGNUMBER* sum, NODE* nodeNumber1, NODE* nodeNumber2, int carry);
static void diff_nodes(BIGNUMBER *sum, NODE *nodeNumber1, NODE *nodeNumber2, int carry);
static boolean compare_node_per_node(NODE* nodeNumber1, NODE* nodeNumber2);

struct node_
{
    int value;
    NODE *next;
};

struct bigNumber_
{
    NODE *start;
    NODE *end;
    int size;
    boolean isSigned; 
};

BIGNUMBER * bignumber_create(char *input)
{
    BIGNUMBER* bigNumber = (BIGNUMBER*) malloc(sizeof(BIGNUMBER));
    bigNumber->size = 0;
    
    int inputSize = strlen(input);
    int count = 0, nodeValue = 0;

    char tempChar = ' ';

    // Substitui o sinal de números negativos por um espaço em branco
    if (input[0] == '-')
    {
        input[0] = ' ';
        bigNumber->isSigned = TRUE;
    }
    else
    {
        bigNumber->isSigned = FALSE;
    }

    // Substitui zeros a esquerda por espaços em branco
    removing_leading_zeros(input);

    for (int i = inputSize-1; i >= 0; i--)
    {
        if (input[i] != ' ')
        {
            tempChar = input[i];

            if (tempChar != 0)
            {
                nodeValue += (tempChar - '0')*pow(10, count);
            }
            
            count ++;

            if (count == 4 || i - 1 < 0 || input[i-1] == ' ')
            {
                insert_node_on_end(bigNumber, nodeValue);
                nodeValue = 0;
                count = 0;
            }
        }        
    }

    return bigNumber;
}

void removing_leading_zeros(char* input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (i + 1 < strlen(input))
        {
            if (input[i] == '0' && input[i+1] == 0)
            {
                input[i] = ' ';
            }
            else
            {
                break;
            }
        }
    }
}

void insert_node_on_start(BIGNUMBER *bigNumber, int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;

    if (bigNumber->size == 0)
    {
        newNode->next = NULL;
        bigNumber->end = newNode;
    }
    else
    {
        newNode->next = bigNumber->start;
    }

    bigNumber->start = newNode;
    bigNumber->size++;
}

void insert_node_on_end(BIGNUMBER *bigNumber, int value)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->value = value;
    newNode->next = NULL;

    if (bigNumber->size == 0)
    {
        bigNumber->start = newNode;
    }
    else
    {
        bigNumber->end->next = newNode;
    }

    bigNumber->end = newNode;
    bigNumber->size++;
}

void bignumber_print(BIGNUMBER *bigNumber)
{
    if (bigNumber->isSigned == TRUE)
    {
        printf("-");
    }

    print_node(bigNumber->start);

    printf("\n");
}

void print_node(NODE *node)
{
    if (node != NULL)
    {
        print_node(node->next);

        if (node->next == NULL)
        {
            printf("%d", node->value);
        }
        else
        {
            printf("%04d", node->value);
        }
    }
}

BIGNUMBER* bignumber_sum(BIGNUMBER *bigNumber1, BIGNUMBER *bigNumber2)
{
    BIGNUMBER *sum = (BIGNUMBER *)malloc(sizeof(BIGNUMBER));
    sum->size = 0;

    if (bigNumber1->isSigned == bigNumber2->isSigned)
    {
        sum->isSigned = bigNumber1->isSigned;
        sum_nodes(sum, bigNumber1->start, bigNumber2->start, 0);
    }
    else
    {
        if (bignumber_abs_greater_than(bigNumber1, bigNumber2))
        {
            sum->isSigned = bigNumber1->isSigned;
            diff_nodes(sum, bigNumber1->start, bigNumber2->start, 0);
        }
        else
        {
            sum->isSigned = bigNumber2->isSigned;
            diff_nodes(sum, bigNumber2->start, bigNumber1->start, 0);
        }
    }

    if (sum->start->value == 0 && sum->size == 1)
    {
        sum->isSigned = FALSE;
    }
    
    return sum;
}

void diff_nodes(BIGNUMBER *sum, NODE *nodeNumber1, NODE *nodeNumber2, int carry)
{
    int result = carry, nextCarry = 0;
    NODE* nextNode1 = NULL;
    NODE* nextNode2 = NULL;
    
    if (nodeNumber1 != NULL)
    {
        nextNode1 = nodeNumber1->next;  

        while (nodeNumber1->value <= 0)
        {
            nodeNumber1->value += 10000;
            nextCarry -= 1;
        }  
        
        result += nodeNumber1->value;

        if (nodeNumber2 != NULL)
        {
            if (nodeNumber1->value < nodeNumber2->value)
            {
                result += 10000;
                nextCarry -= 1;
            }

            result -= nodeNumber2->value;
            nextNode2 = nodeNumber2->next;    
        }
        
        diff_nodes(sum, nextNode1, nextNode2, nextCarry);
        insert_node_on_start(sum, result);
    } 
}

void sum_nodes(BIGNUMBER *sum, NODE *nodeNumber1, NODE *nodeNumber2, int carry)
{
    int result = carry, nextCarry = 0;
    NODE* nextNode1 = NULL;
    NODE* nextNode2 = NULL;
    
    if (nodeNumber1 != NULL || nodeNumber2 != NULL)
    {
        if (nodeNumber1 != NULL)
        {
            result += nodeNumber1->value;
            nextNode1 = nodeNumber1->next;    
        }

        if (nodeNumber2 != NULL)
        {
            result += nodeNumber2->value;
            nextNode2 = nodeNumber2->next;    
        }

        if (result > 9999)
        {
            result -= 10000;
            nextCarry = 1;
        }
        
        sum_nodes(sum, nextNode1, nextNode2, nextCarry);
        insert_node_on_start(sum, result);
    }
    else
    {
        if (carry != 0)
        {
            insert_node_on_start(sum, carry);
        }    
    } 
}

boolean bignumber_greater_than(BIGNUMBER *bigNumber1, BIGNUMBER *bigNumber2)
{
    if (bigNumber1->isSigned == FALSE && bigNumber2->isSigned == TRUE)
    {
        return TRUE;
    }
    else if (bigNumber1->isSigned == TRUE && bigNumber2->isSigned == FALSE)
    {
        return FALSE;
    }
    else if (bigNumber1->isSigned == FALSE && bigNumber2->isSigned == FALSE)
    {
        return bignumber_abs_greater_than(bigNumber1, bigNumber2);
    }
    else
    {
        return bignumber_abs_greater_than(bigNumber2, bigNumber1);
    }
}

boolean bignumber_abs_greater_than(BIGNUMBER *bigNumber1, BIGNUMBER *bigNumber2)
{
    if (bigNumber1->size > bigNumber2->size)
    {
        return TRUE;
    }
    else if (bigNumber1->size < bigNumber2->size)
    {
        return FALSE;
    }
    else
    {
        if (bigNumber1->end->value > bigNumber2->end->value)
        {
            return TRUE;
        }
        else if (bigNumber1->end->value < bigNumber2->end->value)
        {
            return FALSE;
        }
        else
        {
            return compare_node_per_node(bigNumber1->start, bigNumber2->start);
        }
    }
}

boolean compare_node_per_node(NODE* nodeNumber1, NODE* nodeNumber2)
{
    NODE* tempNode1 = nodeNumber1;
    NODE* tempNode2 = nodeNumber2;

    boolean isGreater = FALSE;

    while (tempNode1 != NULL)
    {
        if (tempNode1->value > tempNode2->value)
        {
            isGreater = TRUE;
        }
        else if (tempNode1->value < tempNode2->value)
        {
            isGreater = FALSE;
        }

        tempNode1 = tempNode1->next;
        tempNode2 = tempNode2->next;
    }
    
    return isGreater;
}

boolean bignumber_less_than(BIGNUMBER *bigNumber1, BIGNUMBER *bigNumber2)
{
    return bignumber_greater_than(bigNumber2, bigNumber1);
}

boolean bignumber_equal(BIGNUMBER *bigNumber1, BIGNUMBER *bigNumber2)
{
    if ((bignumber_greater_than(bigNumber1, bigNumber2) == FALSE) && (bignumber_less_than(bigNumber1, bigNumber2) == FALSE))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void bignumber_delete(BIGNUMBER* bigNumber)
{
    NODE* tempNode = bigNumber->start;
    NODE* loopNode = tempNode->next;

    free(tempNode);

    while (loopNode != NULL)
    {
        tempNode = loopNode;
        loopNode = tempNode->next;

        free(tempNode);
    }
    
    free(bigNumber);
}