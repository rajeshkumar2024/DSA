#include<stdio.h>

#define N 5
int queue[N], front = -1, rear = -1;

int is_full()
{
    return (rear == N-1) ? 1 : 0;
}

int is_empty()
{
    return (front == -1 && rear == -1) ? 1 : 0;
}

void enqueue(int num)
{
    if(is_full())
        printf("\nOverflow!");
    else if(is_empty())
    {
        front = rear = 0;
        queue[rear] = num;
        printf("\nEnqueued %d successfully!",num);
    }
    else
    {
        queue[++rear] = num;
        printf("\nEnqueued %d successfully!",num);
    }
}

void dequeue()
{
    if(is_empty())
        printf("\nEmpty!");
    else if(front == rear)
    {
        printf("\nDequeued %d successfully!",queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nDequeued %d successfully!",queue[front++]);
    }
}

void display()
{
    int i;
    if(is_empty())
        printf("\nEmpty!");
    else
    {
        printf("\n---------------------\n");
        for(i=front; i<=rear; i++)
            printf("%d ",queue[i]);
        printf("\n---------------------\n");
    }
}

void peek()
{
    if(is_empty())
        printf("\nEmpty!");
    else
        printf("\n%d is at front.",queue[front]);
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