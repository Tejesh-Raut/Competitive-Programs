/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int n=1;
    if(A==NULL){
        return NULL;
    }
    ListNode* a = A;
    
    while(a->next!=NULL){
        n++;
        a = a->next;
    }
    a->next = A;
    B= B%n;
    for(int i=0; i<(n-B); i++){
        a = a->next;
    }
    ListNode* ans = a->next;
    a->next = NULL;
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
