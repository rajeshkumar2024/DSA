#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

// tail->next = head

void display(node *tail) {
    if(tail == NULL) {
        printf("List is empty!\n");
        return;
    } else {
        node *tmp = tail->next;
        do {
            printf("%d->",tmp->data);
            tmp = tmp->next;
        }while(tmp != tail->next);
        printf("START\n");
    }
}

void search(node *tail, int item) {
    node *tmp = tail->next;
    int pos = 1;
    do {
        if(tmp->data == item) {
            printf("%d is at position: %d\n", item, pos);
            return;
        }
        tmp = tmp->next;
        pos++;
    }while(tmp != tail->next);
    printf("Item %d not found in list!\n", item);
}

node *addAtBeg(node *tail, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;

    if(tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
        return tail;
    }

    newNode->next = tail->next;
    tail->next = newNode;
    return tail;
}

node *addAtEnd(node *tail, int data) {
    node *tmp = tail, *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;

    if(tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

node *addAtPos(node *tail, int data, int pos) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;

    if(pos == 1) {
        newNode->next = tail->next;
        tail->next = newNode;
        return tail;
    }

    node *tmp = tail->next;
    for(int i=1; i<pos-1 && tmp != tail; i++) {
        tmp = tmp->next;
    }
    if(tmp == tail) {
        // printf("There are less than %d elements!\n", pos);
        newNode->next = tmp->next;
        tmp->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tmp->next;
        tmp->next = newNode;  
    }
    return tail;
}

node *createList(node *tail) {
    int numberOfNodes, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &numberOfNodes);

    if(numberOfNodes == 0) {
        return tail;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    tail = addAtBeg(tail, data);
    
    for(int i=2; i<=numberOfNodes; i++) {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        tail = addAtEnd(tail, data);
    }
    return tail;
}

node *delAtBeg(node *tail) {
    if(tail == NULL) {
        printf("List is already empty!\n");
        return tail;
    }
    node *tmp = tail->next;
    tail->next = tail->next->next;
    free(tmp);
    return tail;
}

node *delAtEnd(node *tail) {
    if(tail == NULL) {
        printf("List is already empty!\n");
        return tail;
    }
    node *tmp = tail->next;
    if(tmp->next == tmp) {
        free(tmp);
        tail = NULL;
        return tail;
    }
    while(tmp->next->next != tail->next) {
        tmp = tmp->next;
    }
    node *del = tmp->next;
    tmp->next = del->next;
    free(del);
    return tail;
}

node *delAtPos(node *tail, int pos) {
    if(tail == NULL) {
        printf("List is already empty!\n");
        return tail;
    }
    if(pos == 1) {
        tail = delAtBeg(tail);
        return tail;
    }
    node *tmp = tail->next, *delNode;
    for(int i=1; i<pos-1 && tmp != tail; i++) {
        tmp = tmp->next;
    }
    if(tmp == tail) {
        printf("There are less than %d elements in list.\n", pos);
        return tail;
    }

    delNode = tmp->next;

    if(delNode == tail) {
        tail = tmp;
    }

    tmp->next = delNode->next; //tmp->next->next
    
    free(delNode);
    return tail;
}

node *reverse(node *tail) {
    node *prv = tail, *nxt, *tmp = tail->next;

    while(tmp != tail) {
        nxt = tmp->next;
        tmp->next = prv;
        prv = tmp;
        tmp = nxt;
    }
    tail = tail->next;
    tmp->next = prv;
    return tail;
}

void count(node *tail) {
    node *tmp = tail->next;
    int cnt = 0;
    do {
        cnt++;
        tmp = tmp->next;
    }while(tmp != tail->next);
    printf("Total number of nodes: %d\n", cnt);
}

node *createSortedList(node *tail, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;

    if(tail == NULL || data < tail->next->data) {
        if(tail != NULL) {
            newNode->next = tail->next;
            tail->next = newNode;
        } else {
            newNode->next = newNode;
            tail = newNode;
        }
    } else {
        node *tmp = tail->next;
        while(tmp != tail) {
            if(data <= tmp->next->data) {
                break;
            }
            tmp = tmp->next;
        }
        
        newNode->next = tmp->next;
        tmp->next = newNode;

        if(tmp == tail) {
            tail = newNode;
        }
        
    }
    return tail;
}

int main() {
    node *tail = NULL;
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
                tail = createList(tail);
                break;
            case 2:
                display(tail);
                break;
            case 3:
                count(tail);
                break;
            case 4:
                printf("Enter the element to be searched: ");
                scanf("%d", &item);
                search(tail, item);
                break;
            case 5:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                tail = addAtBeg(tail, data);
                break;
            case 6:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                tail = addAtEnd(tail, data);
                break;
            case 7:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position which to insert: ");
                scanf("%d", &pos);
                tail = addAtPos(tail, data, pos);
                break;
            case 8:
                tail = delAtBeg(tail);
                break;
            case 9:
                tail = delAtEnd(tail);
                break;
            case 10:
                printf("Enter the position which to delete: ");
                scanf("%d", &pos);
                tail = delAtPos(tail, pos);
                break;
            case 11:
                tail = reverse(tail);
                break;
            case 12:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                tail = createSortedList(tail, data);
                break;
            case 0:
                exit(1);
            default:
                printf("Wrong Choice!\n");
        }
    }

    return 0;
}