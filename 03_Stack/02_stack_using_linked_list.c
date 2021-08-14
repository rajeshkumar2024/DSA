#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

node *top = NULL;

int isEmpty() {
    if(top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void push(int item) {
    node *newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }
    newNode->data = item;
    newNode->next = top;
    top = newNode; 
}

int pop() {
    if(isEmpty()) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    int topmost = top->data;
    node *delNode = top;
    top = top->next;
    free(delNode);
    return topmost;
}

void display() {
    if(isEmpty()) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    node *tmp = top;
    while(tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int peek() {
    if(isEmpty()) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return top->data;
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