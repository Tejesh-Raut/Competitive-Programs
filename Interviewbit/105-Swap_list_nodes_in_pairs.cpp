/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseList1(ListNode* A) {
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
ListNode* reverseList(ListNode* A, int B) {
    ListNode* ans = new ListNode(0);
    ans->next = A;
    ListNode* temp;
    ListNode* temp2;
    // ListNode* temp3 = ans;
    ListNode* p = A;
    ListNode* p2 = ans;
    while(true){
        temp = p;
        for(int i=0; i<(B-1); i++){
            if(p->next==NULL){
                break;
            }
            p = p->next;
        }
        temp2 = p->next;
        p->next = NULL;
        p = temp2;
        temp = reverseList1(temp);
        p2->next = temp;
        p2 = temp;
        while(p2->next!=NULL){
            p2 = p2->next;
        }
        p2->next = p;
        if(p==NULL){
            break;
        }
    }
    return ans->next;
}
ListNode* Solution::swapPairs(ListNode* A) {
    A = reverseList(A, 2);
    return A;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
