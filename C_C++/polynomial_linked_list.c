#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coeff;
    int expo;
    struct node *next;
}node;

node *head = NULL, *new_node, *temp;

void create_polynomial(int n)
{
    new_node = (node *)malloc(sizeof(node));
    if(n == 0)
        printf("Enter constant : ",n);
    else
        printf("Enter coefficient of X^%d : ",n);
    scanf("%d",&new_node->coeff);
    new_node->expo = n;
    new_node->next = NULL;
    if(head == NULL)
    {
        head = new_node;
        temp = head;
    }
    else
    {
        temp->next = new_node;
        temp = new_node;
    }
}

void display_polynomial()
{
    temp = head;
    printf("\n----------------------------------\n");
    while(temp != NULL)
    {
        if(temp->expo == 0)
        {
            if(temp->coeff > 0)
                printf("+ %d",temp->coeff);
            else
                printf("- %d",-1*temp->coeff);
        }
        else
        {
            if(temp->coeff > 0)
            {
                if(temp == head)
                    printf("%dX^%d ",temp->coeff,temp->expo);
                else
                    printf("+ %dX^%d ",temp->coeff,temp->expo);   
            }
            else
            {
                printf("- %dX^%d ",-1*temp->coeff,temp->expo);
            }   
        }
        temp = temp->next;
    }
    printf("\n----------------------------------\n");
}

int main()
{
    int degree, i;
    printf("\nEnter highest degree: ");
    scanf("%d",&degree);
    printf("\n____________creating______________\n");
    for(i=degree; i>=0; i--)
    {
        create_polynomial(i);
    }
    printf("_____________created______________\n");
    display_polynomial();
    return 0;
}