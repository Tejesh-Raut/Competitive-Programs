/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* A1;
    ListNode* p1;
    ListNode* A2;
    ListNode* p2;
    ListNode* p;
    if(A->val<B){
        A1 = A;
        p1 = A1;
        if(p1->next == NULL){
            return A;
        }
        while(p1->next->val<B){
            p1 = p1->next;
            if(p1->next==NULL){
                return A;
            }
        }
        A2 = p1->next;
        p2 = A2;
        p = p1->next;
        if(p==NULL){
            return A;
        }
    }
    else{
        A2 = A;
        p2 = A2;
        if(p2->next==NULL){
            return A;
        }
        while(p2->next->val>=B){
            p2 = p2->next;
            if(p2->next==NULL){
                return A;
            }
        }
        A1 = p2->next;
        p1 = A1;
        p = p2->next;
        if(p==NULL){
            return A;
        }
    }
    p = p->next;
    while(p!=NULL){
        if(p->val <B){
            p1->next = p;
            p1 = p1->next;
        }
        else{
            p2->next = p;
            p2 = p2->next;
        }
        p = p->next;
    }
    p1->next = A2;
    p2->next = NULL;
    return A1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
