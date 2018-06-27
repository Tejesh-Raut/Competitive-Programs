/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A==NULL){
        return B;
    }
    if(B==NULL){
        return A;
    }
    ListNode* ans;
    ListNode* a = A;
    ListNode* b = B;
    if(A->val < B->val){
        ans = A;
        a = A->next;
    }
    else{
        ans = B;
        b= B->next;
    }
    ListNode* final_ans = ans;
    while((a!=NULL)||(b!=NULL)){
        if(a==NULL){
            ans->next = b;
            return final_ans;
        }
        if(b==NULL){
            ans->next = a;
            return final_ans;
        }
        if(a->val<b->val){
            ans->next = a;
            ans = ans->next;
            a = a->next;
        }
        else{
            ans->next = b;
            ans = ans->next;
            b = b->next;
        }
    }
    return final_ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
