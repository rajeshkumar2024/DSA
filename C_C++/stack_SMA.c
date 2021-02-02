#include<stdio.h>

#define N 10

int stack[N];
int top = -1, temp;

void push()
{
    printf("\nEnter data: ");
    scanf("%d",&temp);
    if(top == N-1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        top++;
        stack[top] = temp;
        printf("Pushed %d successfully!",stack[top]);
    }
}

void pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\nPoped %d successfully!",stack[top]);
        top--;
    }
}

void display()
{
    printf("\n");
    if(top == -1)
    {
        printf("Stack Underflow!");
        return;
    }
    for(temp=top; temp>=0; temp--)
    {
        printf("| %d |\n",stack[temp]);
        if(temp == 0)
            printf("^^^^^\n");
        else
            printf("-----\n");
    }
}

void peek()
{
    if(top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\nTopmost integer: %d",stack[top]);
    }
}

void length()
{
    if(top == -1)
    {
        printf("Length is: 0");
        return;
    }
    printf("Length is: %d",top+1);
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