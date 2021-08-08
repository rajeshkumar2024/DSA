#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

void display(node *head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    } else {
        node *tmp = head;
        while(tmp != NULL) {
            printf("%d->",tmp->data);
            tmp = tmp->next;
        }
        printf("NULL\n");
    }
}

void search(node *head, int item) {
    node *tmp = head;
    int pos = 1;
    while(tmp != NULL) {
        if(tmp->data == item) {
            printf("%d is at position: %d\n", item, pos);
            return;
        }
        tmp = tmp->next;
        pos++;
    }
    printf("Item %d not found in list!\n", item);
}

node *addAtBeg(node *head, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

node *addAtEnd(node *head, int data) {
    node *tmp = head, *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    return head;
}

node *addAtPos(node *head, int data, int pos) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    node *tmp = head;
    for(int i=1; i<pos-1 && tmp != NULL; i++) {
        tmp = tmp->next;
    }
    if(tmp == NULL) {
        printf("There are less than %d elements!\n", pos);
    } else {
        newNode->next = tmp->next;
        tmp->next = newNode;  
    }
    return head;
}

node *createList(node *head) {
    int numberOfNodes, data;
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

node *delAtBeg(node *head) {
    if(head == NULL) {
        printf("List is already empty!\n");
        return head;
    }
    node *tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

node *delAtEnd(node *head) {
    if(head == NULL) {
        printf("List is already empty!\n");
        return head;
    }
    node *tmp = head;
    if(tmp->next == NULL) {
        head = head->next;
        free(tmp);
        return head;
    }
    while(tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
    return head;
}

node *delAtPos(node *head, int pos) {
    if(head == NULL) {
        printf("List is already empty!\n");
        return head;
    }
    if(pos == 1) {
        head = delAtBeg(head);
        return head;
    }
    node *tmp = head, *delNode;
    for(int i=1; i<pos-1 && tmp != NULL; i++) {
        tmp = tmp->next;
    }
    if(tmp == NULL || tmp->next == NULL) {
        printf("There are less than %d elements in list.\n", pos);
        return head;
    }
    delNode = tmp->next;
    tmp->next = tmp->next->next;
    free(delNode);
    return head;
}

node *reverse(node *head) {
    node *prv = NULL, *nxt, *tmp = head;

    while(tmp != NULL) {
        nxt = tmp->next;
        tmp->next = prv;
        prv = tmp;
        tmp = nxt;
    }
    head = prv;
    return head;
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

node *createSortedList(node *head, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;

    if(head == NULL || data < head->data) {
        newNode->next = head;
        head = newNode;
    } else {
        node *tmp = head;
        while(tmp->next != NULL) {
            if(data <= tmp->next->data) {
                break;
            }
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
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
        printf("7. Add at position\n");
        printf("8. Delete at beginning\n");
        printf("9. Delete at end\n");
        printf("10. Delete at position\n");
        printf("11. Reverse\n");
        printf("12. Create sorted list\n");
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
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position which to insert: ");
                scanf("%d", &pos);
                head = addAtPos(head, data, pos);
                break;
            case 8:
                head = delAtBeg(head);
                break;
            case 9:
                head = delAtEnd(head);
                break;
            case 10:
                printf("Enter the position which to delete: ");
                scanf("%d", &pos);
                head = delAtPos(head, pos);
                break;
            case 11:
                head = reverse(head);
                break;
            case 12:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                head = createSortedList(head, data);
                break;
            case 0:
                exit(1);
            default:
                printf("Wrong Choice!\n");
        }
    }

    return 0;
}