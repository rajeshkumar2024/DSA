//Fixed many lines in the program
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node node;

void display(node *head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }
    node *tmp = head;
    while(tmp != NULL) {
        printf("%d<->", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void search(node *head, int data) {
    node *tmp = head;
    int pos = 1;
    while(tmp != NULL) {
        if(tmp->data == data) {
            printf("%d is found at pos: %d\n", data, pos);
            return;
        }
        pos++;
        tmp = tmp->next;
    }
    printf("Item is not found!\n");
}

void count(node *head) {
    node *tmp = head;
    int cnt = 0;
    while(tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    printf("Total number of nodes: %d\n", cnt);
}

node *reverse(node *head) {
    node *tmp = head, *nxt, *prv = NULL;
    while(tmp != NULL) {
        nxt = tmp->next;
        tmp->prev = nxt;
        tmp->next = prv;
        prv = tmp;
        tmp = nxt;
    }
    head = prv;
    return head;
}

node *addAtBeg(node *head, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL) {
        head->prev = newNode;
    }

    head = newNode;

    return head;
}

node *addAtEnd(node *head, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }

    node *tmp = head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
    return head;
}

node *createList(node *head) {
    int data, numberOfNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numberOfNodes);

    if(numberOfNodes == 0) {
        return head;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    head = addAtBeg(head, data);

    for(int i=2; i<=numberOfNodes; i++) {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        head = addAtEnd(head, data);
    }
    return head;
}

node *delAtBeg(node* head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        node *tmp = head;
        head = head->next;
        head->prev = NULL;
        free(tmp);
    }
    
    return head;
}

node *delAtEnd(node *head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    node *tmp = head, *delNode;

    if(tmp->next == NULL) {
        delNode = tmp;
        head = NULL;
        free(delNode);
        return head;
    }

    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    delNode = tmp;
    tmp->prev->next = NULL;
    free(delNode);
    return head;
}


int main() {
    node *head = NULL;
    int choice, data, pos, item;

    while(1) {
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Search\n");
        printf("5. Add at beginning\n");
        printf("6. Add at end\n");
        printf("7. Delete at beginning\n");
        printf("8. Delete at end\n");
        printf("9. Reverse\n");
        printf("0. Exit!\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                head = createList(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                count(head);
                break;
            case 4:
                printf("Enter the element to be searched: ");
                scanf("%d", &item);
                search(head, item);
                break;
            case 5:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                head = addAtBeg(head, data);
                break;
            case 6:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                head = addAtEnd(head, data);
                break;
            case 7:
                head = delAtBeg(head);
                break;
            case 8:
                head = delAtEnd(head);
                break;
            case 9:
                head = reverse(head);
                break;
            case 0:
                exit(1);
            default:
                printf("Wrong Choice!\n");
        }
    }

    return 0;
}