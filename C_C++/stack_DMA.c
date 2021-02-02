#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *top = NULL, *temp, *new_node;

void push()
{
    new_node = (node *)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d",&new_node->data);
    new_node->next = top;
    top = new_node;
    printf("Pushed %d successfully!",new_node->data);
}

void pop()
{
    if(top == NULL)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\nPoped %d successfully!",top->data);
        temp = top;
        top = top->next;
        free(temp);  
    }
}

void display()
{
    printf("\n");
    if(top == NULL)
    {
        printf("Stack Underflow!");
    }
    else
    {
        temp = top;
        while(temp != NULL)
        {
            printf("| %d |\n", temp->data);
            if(temp->next == NULL)
                printf("^^^^^\n");
            else
                printf("-----\n");
            temp = temp->next;
        }
    }
}

void peek()
{
    if(top == NULL)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\nTopmost integer: %d",top->data);
    }
}

void length()
{
    int count = 0;
    temp = top;
    if(top == NULL)
    {
        printf("\nLength: 0");
    }
    else
    {
        temp = top;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        printf("\nLength: %d",count);
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n\n_______Options______\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Get length\n0. Exit!\n");
        printf("````````````````````\n");
        printf("Select option: ");
        scanf("%d",&choice);
        if (choice == 0)
            break;
        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            case 5: length();
                    break;
            default: printf("Enter correct choice!");
        }
    }
    return 0;
}