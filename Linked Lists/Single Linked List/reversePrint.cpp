void reversePrint(SinglyLinkedListNode* llist) {

    if(llist == nullptr) {
        return;
    }
    reversePrint(llist->next);
    cout << llist->data << endl;
}