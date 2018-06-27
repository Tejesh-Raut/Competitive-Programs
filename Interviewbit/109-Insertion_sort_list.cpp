/*
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* ans = new ListNode(0);
    ans->next = A;
    ListNode* p = ans->next;
    if(A==NULL){
        return NULL;
    }
    ListNode* p1;
    ListNode* temp;
    while(p->next!=NULL){
        if(p->val < p->next->val){
            p = p->next;
        }
        else{
            temp = p->next;
            p->next = p->next->next;
            p1 = ans;
            while(p1->next->val < temp->val){
                p1 = p1->next;
            }
            temp->next = p1->next;
            p1->next = temp;
        }
    }
    return ans->next;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
