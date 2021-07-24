bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode *tmp1 = head1, *tmp2 = head2;
    int len1 = 0, len2 = 0;
    string data1 = "", data2 = "";
    
    while(tmp1 != nullptr) {
        len1++;
        data1 = to_string(tmp1->data) + data1;
        tmp1 = tmp1->next;
    }
    
    while(tmp2 != nullptr) {
        len2++;
        data2 = to_string(tmp2->data) + data2;
        tmp2 = tmp2->next;
    }
    
    if(len1 == len2 && data1 == data2) {
        return true;
    }
    return false;

}