SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {

    SinglyLinkedListNode *tmp, *ptr = llist;
    
    if(position==0) {
        tmp = llist;
        llist = llist->next;
        free(tmp);
        return llist;
    }
    
    for(int i=0; i<position-1; i++) {
        ptr = ptr->next;
    }
    tmp = ptr->next;
    ptr->next = tmp->next;
    free(tmp);
    return llist;
}