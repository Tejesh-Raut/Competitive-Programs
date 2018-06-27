/*
Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* sortedMerge(ListNode* a, ListNode* b){
    ListNode* result = NULL;
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    if(a->val<= b->val){
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else{
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}
void FrontBackSplit(ListNode* head, ListNode** a, ListNode** b){
    ListNode* fast;
    ListNode* slow;
    if((head==NULL)&&(head->next==NULL)){
        *a = head;
        *b = NULL;
    }
    else{
        slow = head;
        fast = head->next;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        *a = head;
        *b = slow->next;
        slow->next = NULL;
    }
}
ListNode* Solution::sortList(ListNode* A) {
    // ListNode* ans = new ListNode(0);
    // ans->next = A;
    ListNode* head = A;
    ListNode* a;
    ListNode* b;
    if((head==NULL)||(head->next == NULL)){
        return A;
    }
    FrontBackSplit(head, &a, &b);
    a = sortList(a);
    b = sortList(b);
    A = sortedMerge(a, b);
    return A;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
