/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* a =A;
    ListNode* b =A->next;
    while(true){
        if((a==NULL)||(b==NULL)){
            return NULL;
        }
        if(a==b){
            break;
        }
        a= a->next;
        if(b->next == NULL){
            return NULL;
        }
        b = b->next->next;
    }
    int n=1;
    a = a->next;
    while(a!=b){
        n++;
        a = a->next;
    }
    a = A;
    b = A;
    for(int i=0; i<n; i++){
        a = a->next;
    }
    while(true){
        if(a==b){
            return a;
        }
        a = a->next;
        b = b->next;
    }
    return NULL;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
