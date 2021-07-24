void printLinkedList(SinglyLinkedListNode* head) {

    SinglyLinkedListNode *tmp = head;
    
    while(tmp != nullptr) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }

}