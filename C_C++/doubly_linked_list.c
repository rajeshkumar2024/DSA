#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;
node *head = NULL, *new_node, *temp, *current_node, *next_node, *tail;
int i, pos;
void create_list(int data)
{
    fflush(stdin);
    new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if(head == NULL)
    {
        head = temp = tail = new_node;
    }
    else
    {
        temp->next = new_node;
        new_node->prev = temp;
        temp = new_node;
        tail = temp;
    }
}
void display()
{
    temp = head;
    printf("\n--------------Your list--------------\n");
    while(temp != NULL)
    {
        printf("|%d| ",temp->data);
        temp = temp->next;
    }
    printf("\n---------------XXXXXXX---------------\n");
}
void insert_at_beg()
{
    fflush(stdin);
    new_node = (node *)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d",&new_node->data);
    new_node->prev = NULL;
    new_node->next = NULL;
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
    printf("Inserted successfully!");
}
void insert_at_end()
{
    fflush(stdin);
    new_node = (node *)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d",&new_node->data);
    tail->next = new_node;
    new_node->prev = tail;
    new_node->next = NULL;
    tail = new_node;
    printf("Inserted successfully!");
}
void insert_at_pos(int count)
{
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    if(pos > count || pos < 1)
    {
        printf("Invalid position!");
    }
    else if(pos == 1)
    {
        insert_at_beg();
    }
    else
    {
        i = 1;
        temp = head;
        while(i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        new_node = (node *)malloc(sizeof(node));
        printf("Enter data: ");
        scanf("%d", &new_node->data);
        new_node->prev = temp;
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->next->prev = new_node;
        printf("Inserted successfully!");
    }
}
void del_at_beg()
{
    if(head == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        printf("Deleted successfully!");
    }
}
void del_at_end()
{
    if(tail == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        temp = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        free(temp);
        printf("Deleted successfully!");
    }
}
void del_at_pos(int count)
{
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    if(pos < 1 || pos > count)
    {
        printf("Invalid position!");
    }
    else if(pos == 1)
    {
        del_at_beg();
    }
    else if(pos == count)
    {
        del_at_end();
    }
    else
    {
        i = 1;
        temp = head;
        while(i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        printf("Deleted successfully!");
    }
}
void reverse_list()
{
    current_node = head;
    while(current_node != NULL)
    {
        next_node = current_node->next;
        current_node->next = current_node->prev;
        current_node->prev = next_node;
        current_node = next_node;
    }
    current_node = head;
    head = tail;
    tail = current_node;
    printf("\nReversed successfully!");
}
int total_nodes()
{
    int count = 0;
    temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
int main()
{
    int choice, num;
    char ch;
    printf("__________Creating the list_________\n");
    while(1)
    {
        printf("Enter data: ");
        scanf("%d",&num);
        create_list(num);
        printf("Do you want to continue(y/n): ");
        scanf("%c",&ch);
        if(ch == 'n' || ch == 'N')
        {
            printf("___________List is created__________\n");
            break;
        }
    }
    while(1)
    {
        printf("\n\n1. Display the list\n2. Insert data to the beginning\n");
        printf("3. Insert data to the end\n4. Insert data to the position\n");
        printf("5. Delete data from the beginning\n6. Delete data from the end\n");
        printf("7. Delete data from the position\n8. Reverse the list\n");
        printf("9. Get length of the list\n0. Exit!!!\n");
        printf("\nSelect the option: ");
        scanf("%d",&choice);
        if(choice == 0)
            break;
        switch(choice)
        {
            case 1: display();
                    break;
            case 2: insert_at_beg();
                    break;
            case 3: insert_at_end();
                    break;
            case 4: insert_at_pos(total_nodes());
                    break;
            case 5: del_at_beg();
                    break;
            case 6: del_at_end();
                    break;
            case 7: del_at_pos(total_nodes());
                    break;
            case 8: reverse_list();
                    break;
            case 9: printf("\nTotal number of nodes are: %d", total_nodes());
                    break;
            default: printf("\nSelect the proper option!");
        }
    }
    return 0;
}