SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {

    SinglyLinkedListNode *newNode, *temp;
    
    newNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    
    newNode->data = data;
    newNode->next = NULL;
    
    if(position == 0) {
        newNode->next = llist->next;
        llist = newNode;
        return llist;
    }
    
    temp = llist;
    
    for(int i=0; i<position-1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    
    return llist;

}