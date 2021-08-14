#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node *rear = NULL;

int isEmpty() {
    if(rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enQueue(int data) {
    node *newNode = (node *)malloc(sizeof(node));

    if(newNode == NULL) {
        printf("Queue Overflow!\n");
        return;
    }

    newNode->data = data;

    if(isEmpty()) {
        rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
}

int deQueue() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    
    node *tmp = rear->next;
    int item = tmp->data;

    if(rear->next == rear) {
        rear = NULL;
    } else {
        rear->next = tmp->next;
    }
    
    free(tmp);

    return item;
}

void display() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    node *tmp = rear->next;

    do {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }while(tmp != rear->next);
    printf("\n");
}

int peek() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    return rear->next->data;
}

int main() {
    int choice, data;
    while(1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                enQueue(data);
                break;
            case 2:
                printf("%d is dequeued\n", deQueue());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("%d ia at peak\n", peek());
                break;
            case 0:
                exit(1);
            default:
                printf("Wrong choice!\n");
        }
    }
    return 0;
}