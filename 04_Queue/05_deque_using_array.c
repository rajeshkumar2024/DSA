#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int front = -1, rear = -1;
int queue[MAX];

int isFull() {
    if((front == 0 && rear == MAX-1) || (front == rear+1)) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if(front == -1) {
        return 1;
    } else {
        return 0;
    }
}

void insertFromRearEnd(int data) {
    if(isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if(front == -1) {
        front = rear = 0;
    } else if(rear == MAX-1) {
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = data;
}

void insertFromFrontEnd(int data) {
    if(isFull()) {
        printf("Queue Overflow!\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    } else if(front == 0) {
        front = MAX-1;
    } else {
        front--;
    }
    queue[front] = data;
}

int deleteFromRearEnd() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    int item = queue[rear];

    if(front == rear) {
        front = rear = -1;
    } else if(rear == 0) {
        rear = MAX-1;
    } else {
        rear--;
    }

    return item;
}

int deleteFromFrontEnd() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }

    int item = queue[front];

    if(front == rear) {
        front = rear = -1;
    } else if(front == MAX-1) {
        front = 0;
    } else {
        front++;
    }

    return item;
}

void display() {
    if(isEmpty()) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    int i = front;
    if(front <= rear) {
        while(i <= rear) {
            printf("%d ", queue[i++]);
        }
    } else {
        while(i <= MAX-1) {
            printf("%d ", queue[i++]);
        }
        i = 0;
        while(i <= rear) {
            printf("%d ", queue[i++]);
        }
    }
    printf("\n");
}


int main() {
    int choice, data;
    while(1) {
        printf("1. Insert at the front end\n");
        printf("2. Insert at the rear end\n");
        printf("3. Delete from font end\n");
        printf("4. Delete from rear end\n");
        printf("5. Display\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the data to be inserted at the front end: ");
                scanf("%d", &data);
                insertFromFrontEnd(data);
                break;
            case 2:
                printf("Enter the data to be inserted at the rear end: ");
                scanf("%d", &data);
                insertFromRearEnd(data);
                break;
            case 3:
                printf("%d is deleted from the front end\n", deleteFromFrontEnd());
                break;
            case 4:
                printf("%d is deleted from the rear end\n", deleteFromRearEnd());
                break;
            case 5:
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