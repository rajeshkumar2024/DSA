#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int front = -1, rear = -1;
int queue[MAX];

int isFull() {
    if(rear == MAX-1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if(front == -1 || front == rear+1) {
        return 1;
    } else {
        return 0;
    }
}

void enQueue(int data) {
    if(isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if(front == -1) {
        front = 0;
    }
    queue[++rear] = data;
}

int deQueue() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    int item = queue[front];
    front++;
    return item;
}

void display() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    for(int i=front; i<=rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int peek() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    return queue[front];
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