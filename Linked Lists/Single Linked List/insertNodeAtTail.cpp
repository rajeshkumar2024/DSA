SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    
    SinglyLinkedListNode *hold = head;

    SinglyLinkedListNode *tmp = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    
    tmp->data = data;
    tmp->next = NULL;
    
    if(head == NULL) {
        head = tmp;
        return head;    
    }
    while(hold->next != NULL) {
        hold = hold->next;
    }
    
    hold->next = tmp;
    
    return head;

}