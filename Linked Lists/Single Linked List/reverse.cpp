SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    
    SinglyLinkedListNode *tmp = llist, *prev = NULL, *nxt;
    
    while(tmp != NULL) {
        nxt = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = nxt;
    }
    llist = prev;
    
    return llist;
}