#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top = -1;
int stack[MAX];

int isFull() {
    if(top == MAX-1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if(top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(int data) {
    if(isFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if(isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

void display() {
    if(isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    for(int i=top; i>=0; i--) {
        printf("%d\n", stack[i]);
    }
    printf("\n");
}

int peek() {
    if(isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top];
}


int main() {
    int choice, item;
    while(1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                printf("%d is popped!\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("%d is at peak\n", peek());
                break;
            case 0:
                exit(1);
                break;
            default:
                printf("Wrong Choice\n");
        }
    }
    return 0;
}