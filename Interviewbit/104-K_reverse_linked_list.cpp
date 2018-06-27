/*
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.


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
ListNode* Solution::reverseList(ListNode* A, int B) {
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
