SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    
    SinglyLinkedListNode *tmp = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    
    tmp->data = data;
    tmp->next = llist;
    
    llist = tmp;
    
    return llist;

}