/*
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.


*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode* A){
    if(A==NULL){
        return 0;
    }
    if(A->next == NULL){
        return 1;
    }
    else{
        return (1+length(A->next));
    }
}
ListNode* reverseList(ListNode* A) {
    if(A==NULL){
        return NULL;
    }
    ListNode* temp;
    temp = A->next; // 2
    A->next = NULL; // 1->0
    ListNode* prev = A; // 1
    ListNode* temp1 = temp; // 2
    while(temp!=NULL){
        temp = temp->next; // 3
        temp1->next = prev; // 2->1
        prev = temp1; // 2
        temp1 = temp; // 3
    }
    return prev;
}
/*
ListNode* Solution::reorderList(ListNode* A) {
    ListNode* a = A;
    while(a!=NULL){
        a->next = reverseList(a->next);
        a = a->next;
    }
    return A;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
*/
ListNode* Solution::reorderList(ListNode* A){
    int n = length(A);
    ListNode* A2 = A;
    for(int i=0; i<(n/2); i++){
        A2 = A2->next;
    }
    ListNode* temp;
    temp = A2->next;
    A2->next = NULL;
    A2 = temp;
    A2 = reverseList(A2);
    ListNode* A1 = A;
    ListNode* temp1;
    ListNode* temp2;
    // temp1 = A1->next;
    // A1->next = A2;
    // A1 = temp1;
    while((A1!=NULL)&&(A2!=NULL)){
        temp1 = A1->next;
        A1->next = A2;
        A1 = temp1;
        temp2 = A2->next;
        A2->next = A1;
        A2 = temp2;
    }
    return A;
}