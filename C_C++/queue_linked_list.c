#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *front = NULL, *rear = NULL, *new_node, *temp;

int is_full()
{
    return (new_node == NULL) ? 1 : 0;
}

int is_empty()
{
    return (front == NULL) ? 1 : 0;
}

void enqueue(int num)
{
    new_node = (node *)malloc(sizeof(node));
    if(is_full())
    {
        printf("\nEnqueued %d unsuccessfully!",num);
        return;
    }
    new_node->data = num;
    new_node->next = NULL;
    if(is_empty())
        front = rear = new_node;
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
    printf("\nEnqueued %d successfully!",rear->data);
}

void dequeue()
{
    if(is_empty())
        printf("\nEmpty!");
    else
    {
        temp = front;
        printf("\nDequeued %d successfully!",front->data);
        front = front->next;
        free(temp);
    }
}

void display()
{
    if(is_empty())
        printf("\nEmpty!");
    else
    {
        printf("\n-------------------------\n");
        temp = front;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n-------------------------\n");
    }
}

void peek()
{
    if(is_empty())
        printf("\nEmpty!");
    else
        printf("\n%d is at front.",front->data);
}

int main()
{
    int choice, num;
    while(1)
    {
        printf("\n\n_______Options______\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n0. Exit!\n");
        printf("````````````````````\n");
        printf("Select option: ");
        scanf("%d",&choice);
        if (choice == 0)
            break;
        switch(choice)
        {
            case 1: printf("\nEnter data: ");
                    scanf("%d",&num);
                    enqueue(num);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            default: printf("\nEnter correct choice!");
        }
    }
    return 0;
}