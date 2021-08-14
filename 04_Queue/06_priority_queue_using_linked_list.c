#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

typedef struct node node;

node *front = NULL;

int isEmpty() {
    if(front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enQueue(int data, int dataPriority) {
    node *newNode = (node *)malloc(sizeof(node));

    if(newNode == NULL) {
        printf("Queue Overflow!\n");
        return;
    }

    newNode->data = data;
    newNode->priority = dataPriority;

    if(isEmpty() || dataPriority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        node *tmp = front;
        while(tmp->next != NULL) {
            if(dataPriority < tmp->next->priority) {
                break;
            }
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

int deQueue() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    int item = front->data;
    node *tmp = front;
    front = front->next;

    free(tmp);

    return item;
}

void display() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    node *tmp = front;
    printf("P ~ Priority & D ~ Data\n");
    while(tmp != NULL) {
        printf("(P=%d | D=%d) ", tmp->priority, tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    int choice, data, priority;
    while(1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter data priority: ");
                scanf("%d", &priority);
                enQueue(data, priority);
                break;
            case 2:
                printf("%d is dequeued\n", deQueue());
                break;
            case 3:
                display();
                break;
            case 0:
                exit(1);
            default:
                printf("Wrong choice!\n");
        }
    }
    return 0;
}