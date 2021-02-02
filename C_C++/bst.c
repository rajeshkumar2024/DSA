#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
}node;

node *newNode(int item) 
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->info = item;
    tmp->lchild = tmp->rchild = NULL;
    return tmp;
}

node *insert(node *ptr, int ikey) 
{
    if (ptr == NULL) 
        return newNode(ikey);
    if (ikey < ptr->info)
        ptr->lchild = insert(ptr->lchild, ikey);
    else
        ptr->rchild = insert(ptr->rchild, ikey);
    return ptr;
}

void preorder(node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d -> ", ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(node *ptr) 
{
    if (ptr != NULL) 
    {
        inorder(ptr->lchild);
        printf("%d -> ", ptr->info);
        inorder(ptr->rchild);
    }
}

void postorder(node *ptr)
{
    if (ptr == NULL) 
        return; 
    postorder(ptr->lchild); 
    postorder(ptr->rchild); 
    printf("%d -> ", ptr->info);
}

int main()
{
    node *root = NULL, *ptr;
    int choice, k;
    while (1)
    {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("0. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the key to be inserted : ");
                scanf("%d", &k);
                root = insert(root, k);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 0:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}