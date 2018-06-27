/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.


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
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int n = length(A);
    if(B>=n){
        return A->next;
    }
    ListNode* p = A;
    for(int i=0; i<(n-B-1); i++){
        p = p->next;
    }
    p->next = p->next->next;
    return A;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
