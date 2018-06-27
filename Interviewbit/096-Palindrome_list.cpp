/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

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
int Solution::lPalin(ListNode* A) {
    int n = length(A);
    int d = n/2;
    ListNode* a=A;
    for(int i=0; i<d; i++){
        a = a->next;
    }
    ListNode* b = reverseList(a);
    a = A;
    for(int i=0; i<d; i++){
        if((a->val)!=(b->val)){
            return 0;
        }
        a = a->next;
        b = b->next;
    }
    return 1;
}
